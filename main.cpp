#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <climits>
#include <cstring>
#include <vector>
#include <fstream>
#include <stack>
#include <algorithm>
#include <chrono>
#include "runs.hpp"
#include "intervaltree.hpp"


using namespace std;
using namespace Intervals;

// using namespace PrioritySearchTree;
typedef int64_t INT;

#define FOR(I, A, B) for (INT I = (A); I <= (B); I++)
#define FORD(I, A, B) for (INT I = (A); I >= (B); I--)
#define REP(I, N) for (INT I = 0; I < (N); I++)
#define VAR(V, init) __typeof(init) V = (init)
#define FORE(I, C) for (VAR(I, (C).begin()); I != (C).end(); I++)

// int is_periodic_yes = 0, is_periodic_no = 0;
// double is_periodic_runtime = 0, aperiodic_survive_runtime = 0, periodic_survive_runtime = 0, create_cluster_runtime = 0, greedy_runtime = 0;
// double interval_tree_build_runtime = 0, interval_query_runtime = 0, check_freq_periodic_survive_runtime = 0, forward_runtime = 0, OUTPUT_runtime = 0;
// double success_setting_runtime = 0, success_child_setting_runtime = 0, fail_setting_runtime = 0, fail_child_setting_runtime = 0;
// int sum_sel=0, count_sel=0;

INT read_patterns( string pattern_filename, unsigned char ** &patterns, INT &num_patterns)
{	

	ifstream is_patterns;
 	is_patterns.open (pattern_filename, ios::in | ios::binary);
 	
	INT max_len_pattern = 0;
	INT ALLOC_SIZE = 180224;
	INT seq_len = 0;
	INT max_alloc_seq_len = 0;
	INT max_alloc_seqs = 0;
	unsigned char chr = 0;
	
	while ( is_patterns.read(reinterpret_cast<char*>(&chr), 1) )
	{
		if( num_patterns >= max_alloc_seqs )
		{
			patterns = ( unsigned char ** ) realloc ( patterns,   ( max_alloc_seqs + ALLOC_SIZE ) * sizeof ( unsigned char* ) );
			patterns[ num_patterns ] = NULL;
			
			max_alloc_seqs += ALLOC_SIZE;
		}
		
		if( seq_len != 0 && chr == '\n' )
		{
			patterns[ num_patterns ][ seq_len ] = '\0';
			
			num_patterns++;

			if( seq_len > max_len_pattern)
				max_len_pattern = seq_len;
			
			seq_len = 0;
			max_alloc_seq_len = 0;
			
			patterns[ num_patterns ] = NULL;
		}
		else 
		{
			if ( seq_len >= max_alloc_seq_len )
			{
				patterns[ num_patterns ] = ( unsigned char * ) realloc ( patterns[ num_patterns ],   ( max_alloc_seq_len + ALLOC_SIZE ) * sizeof ( unsigned char ) );
				max_alloc_seq_len += ALLOC_SIZE;
			}
			
			patterns[ num_patterns ][ seq_len ] = ( unsigned char) chr;	
			seq_len++;	
		}
	} 
	is_patterns.close();
	
return 0;
}

struct STedge;
struct STvertex
{
  	map<unsigned char,STedge, greater<unsigned char>> g; /* edges to children */ // Order the children in descending order to build the SA of this ST
  	STvertex *f; /* suffix link */
  	/* suffix number (0 is the whole word, -1 means the vertex is not a leaf) */
  	INT numer, str_depth_of_N;
    bool flag; /*false: not frequent and survive; true: frequent and survive*/
    vector<STvertex*> path; /*the path from root to this node*/
    vector<int> SA_interval;
};
struct STedge
{
  INT l,r; /* x[l]..x[r] is a piece of text representing an edge */
  STvertex *v;	// The node that this edge points to v (child)
};

STvertex *root;
unsigned char *txt;
INT liscie; /* number of leaves created */

inline void Canonize(STedge &kraw, unsigned char *x)
{
  if (kraw.l<=kraw.r)
  {
    STedge e=kraw.v->g[x[kraw.l]];
    while (e.r-e.l <= kraw.r-kraw.l)
    {
      kraw.l+=e.r-e.l+1;
      kraw.v=e.v;
      if (kraw.l<=kraw.r) e=kraw.v->g[x[kraw.l]];
    }
  }
}

inline bool Test_and_split(STvertex* &w,const STedge &kraw)
{
  w=kraw.v;
  if (kraw.l<=kraw.r)	// If kraw is not in the intial case. Special case: for the intial step, kraw.l=-1, kraw.r=0
  {
    char c=txt[kraw.l];	// get the current first char on the string of edge kraw
    STedge e=kraw.v->g[c];	// create a new edge as the child of kraw with label c
    if (txt[kraw.r+1] == txt[e.l+kraw.r-kraw.l+1]) return true;	// Finish go through the string on kraw and don't need to split
    w=new STvertex; w->numer=-1;	// START to split: create a new node w (-1 not the leaf)
    kraw.v->g[c].r = e.l+kraw.r-kraw.l;
    kraw.v->g[c].v = w;		// Add the new node w between kraw.v and its child
    e.l+=kraw.r-kraw.l+1;
    w->g[txt[e.l]]=e;
    return false;
  } 
  return kraw.v->g.find(txt[kraw.l]) != kraw.v->g.end();
}

void Update(STedge &kraw, INT n)	// kraw: the edge of the current process; n is the length of S
{
  STvertex *oldr=root,*w;
  while (!Test_and_split(w,kraw))	// Test_and_split is false: not split in this function
  {
    STedge e;
    e.v=new STvertex; e.l=kraw.r+1; e.r=n-1;
    e.v->numer=liscie++;
    w->g[txt[kraw.r+1]]=e;
    if (oldr!=root) oldr->f=w;
    oldr=w;
    kraw.v=kraw.v->f;
    Canonize(kraw,txt);
  }
  if (oldr!=root) oldr->f=kraw.v;
}

/* x should have some '$' at the end */
STvertex* Create_suffix_tree(unsigned char *x,INT n)
{
	STvertex *top; /* pinezka */
	STedge e;
	top=new STvertex; root=new STvertex; txt=x;
	top->numer = root->numer = -1;
	e.v=root; liscie=0;	
	// e.l is the index of start char on the edge e, e.r is of end char on e; 
	// top->g[x[i]]: Assign e as one to-child edge of node top 
	REP(i,n) { e.r=-i; e.l=-i; top->g[x[i]]=e; }		
	// Initialize root: Assign the suffix link (f) of root as node top, 
	root->f=top;
	e.l=0; e.v=root; // e.l=0: start position of building the tree
	REP(i,n)	// Go through the S to get each char
	{
	  e.r=i-1; Update(e,n);	// e.r: the current end position of the string on e; n: the length of the S + 1
	  e.r++; Canonize(e,x);
	}
	return root;
}

void STDelete(STvertex *w)
{
  FORE(it,w->g) STDelete(it->second.v);
  delete w;
}



struct Pair 
{
    STvertex * node;
    map<unsigned char, STedge>::iterator it;
    Pair(STvertex * _node, map<unsigned char, STedge>::iterator _it)
    {
        node = _node;
        it = _it;
    }
};


INT add_children( stack<STvertex *> * st, STvertex * current, vector<INT> * leaves )
{
	map<unsigned char, STedge>::iterator indx; 

	for(indx = current->g.begin(); indx != current->g.end(); indx++ )	// Go through all the children of current
	{
	
		if( indx->second.v->numer != -1 )	// numer == -1: It is not a leaf (root or internal node); != -1: It is a leaf, add it to the leaves vector
		{
			leaves->push_back( indx->second.v->numer );
			
		}
		else st->push( indx->second.v );	// It is not a leaf: push it to the stack
	}
	
	
	return 0;
}


vector<INT> search( STvertex * r )
{
	vector<INT> leaves;
	stack<STvertex *> st;

	st.push( r );
	
	while( st.size() > 0 )
	{
		st.pop();
		
		add_children( &st, r, &leaves );
		
		if( st.size() > 0 )
			r = st.top();
	}
		
	return leaves;
}

vector<INT> Find(unsigned char *s,STvertex *r, unsigned char *x)	// *s is the pattern needs to be found, intial *r is the root of ST, *x is the text
{

	vector<INT> occ;
	INT n=strlen( (char*) s);
	
	INT i=0;
	
	while (i<n)
	{
	
		if (r->g.find(s[i]) == r->g.end())	// Finish searching at the end of children of r
			return occ;
		
		STedge e=r->g[s[i]];	// e is the edge toward to the current child s[i] of r
	
		FOR(j,e.l,e.r)
		{
			if( s[i++]!=x[j] )	// if the current char in the pattern s does not match the text x
	  			return occ;
	  			
			if (i == n)
			{
				r = e.v;	// set r to the child corresponding to e.v
				
				if( r->numer == -1 )	// r is not a leaf
				{
					vector<INT> children = search(r);
					
					for(INT a = 0; a<children.size(); a++)	
						occ.push_back( children.at(a) );		
				}
				else occ.push_back( r->numer );
	
				return occ;
			}
		}

		r=e.v;
	}
 	
 	occ.push_back( r->numer );

	return occ;
}

void Print_edge(STedge edge, unsigned char *x) {
	// Print the current info on edge
	unsigned char substring[edge.r - edge.l + 2];
	memcpy(substring, x + edge.l, edge.r - edge.l + 1);
	substring[edge.r - edge.l + 1] = '\0'; // Add null terminator
	cout << "The string on current edge is " << substring << endl;
}

void build_suffix_array(int* suffixArray, int txt_size, STvertex *r){
    for(int i=0; i< txt_size; i++)
        suffixArray[i] = -1;
    
	// Iterative DFS traverse to build the Suffix Array by using stack
	STvertex* current_node = r;
	STvertex* child_node;
	stack<STvertex*> traverse_stack;
	traverse_stack.push(current_node);

	int idx = 0;
	while(!traverse_stack.empty()) {
		current_node = traverse_stack.top();
		traverse_stack.pop();
		map<unsigned char,STedge,greater<unsigned char>> children_map = current_node->g;

		if(current_node->numer > -1 && current_node->numer < txt_size) {	// current_node is a leaf
			// cout << "This is a leaf" << endl;
			// cout << "The numer of this leaf is " << current_node->numer << endl;
			suffixArray[idx] = current_node->numer;
			idx ++;
		}
		else if(current_node->numer == -1) {		// current_node is a internal node
			for (auto const &child : children_map) {
				child_node = child.second.v;
				traverse_stack.push(child_node);
			}
		}
	}
}


vector<STvertex*> bottom_up_SA_interval(STvertex* &r, int* &suffix_array, int* &inv_suffix_array, int txt_size) {
	cout << "The sizeof suffix array is " << txt_size << endl;

	// Stack for traversing the tree
  stack<STvertex*> DFS_stack;
  // Stack to store the post-order traversal (in reverse order)
  stack<STvertex*> bottom_up_stack;
	STvertex* current = r;
  vector<STvertex*> current_path;
  vector<STvertex*> rev_bottomup_ordered_nodes;
  STvertex* child_node;
  vector<STvertex*> child_path;
  map<unsigned char,STedge,greater<unsigned char>> children_map;

  // Start with the root node
  DFS_stack.push(current);
  current_path.push_back(current);
  current->path = current_path;
  current->str_depth_of_N = 0;
  // Traverse the tree using DFS & bottom-up
  cout << "Start DFS traverse!" << endl;

  while (!DFS_stack.empty()) {
    current = DFS_stack.top();
    DFS_stack.pop();
    current->flag = false;
    int current_num = current->numer;
    // vector<STvertex*> current_path = current->path;
    current_path = current->path;
    int current_str_depth = current->str_depth_of_N;
	  children_map = current->g;
    
	  bool is_root = current == r;

	  // cout << "In the DFS traverse, the current.numer is " << current->numer << ", it is root " << is_root << endl;

    vector<int> current_interval;
	  if(current_num > -1 && current_num < txt_size) {	// current is a leaf
      // getting index to SA from invSA
      int current_idx = inv_suffix_array[current_num];
      // Initialize the interval of the current node (leaf)
      
      current_interval.push_back(current_idx);
      current_interval.push_back(current_idx);
    }
    current->SA_interval = current_interval;

	  // Push all the children to the traversal stack (in the order they appear)
	  for (auto const &child : children_map) {
      child_node = child.second.v;
      DFS_stack.push(child_node);
      int child_edge_length = child.second.r - child.second.l + 1;
      // // Print the current child's info on edge
      // Print_edge(child.second, text_string);
      int child_str_depth = current_str_depth + child_edge_length;
      // cout << "The numer of child_node is" << child_node->numer << ", the child_edge_length is " << child_edge_length << ", the child_str_depth is " << child_str_depth << endl; 
      child_path = current_path;
      child_path.push_back(child_node);
      // cout << "After push the child_node to the path, the child_path is " << endl;
      // for (const auto &node : child_path) {
      //   cout << node->numer << " ";
      // }
      // cout << endl;
      child_node->path = child_path;
      child_node->str_depth_of_N = child_str_depth;
      // for (const auto &node : child_path) {
      //   STDelete(node);
      // }
    }

    // Push the current node to the result stack: Don't push the root, as well as the special char $
    if (!is_root && current_num < txt_size) {
      // bottom_up_stack.push(current);
      rev_bottomup_ordered_nodes.push_back(current);
      // cout << "Now push the " << current->numer << " into the result_stack!" << endl;
    }

  }
  // output_stream << "DFS:" << elapsed.count() << " DFS_if_runtime:" << DFS_if_runtime << " DFS_for_runtime:" << DFS_for_runtime << " DFS_set_runtime:" << DFS_set_runtime << " DFS_remain_runtime:" << DFS_remain_runtime << "\n";

	cout << "End DFS traverse, start bottom-up ordered traverse..." << endl;

  // Now, the nodes are in reverse post-order, so we need to process them in the correct order
  for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
    current = *it;

    // auto if_start = chrono::high_resolution_clock::now();
    if(current->SA_interval.size() == 0) {
      // cout << "Didn't find out the record of interval" << endl;
      children_map = current->g;
      vector<int> current_interval;
      int current_min = numeric_limits<int>::max(), current_max = numeric_limits<int>::min();
      for (auto const &child : children_map) {
        vector<int> child_interval = child.second.v->SA_interval;
        if (child_interval[0] < current_min) {
          current_min = child_interval[0];
        }
        if (child_interval[1] > current_max) {
          current_max = child_interval[1];
        }
      }
      current_interval.push_back(current_min);
      current_interval.push_back(current_max);

      current->SA_interval = current_interval;
    }
    // auto if_end = chrono::high_resolution_clock::now();
    // chrono::duration<double> if_elapsed = if_end - if_start;
    // bottomup_if_runtime = bottomup_if_runtime + if_elapsed.count();
  }

  return rev_bottomup_ordered_nodes;
}

IntervalTree<int> is_periodic_preprocessing(unsigned char* text_string, int text_size) {
    // const int MAX_POINTS_DISPLAY = 20;
    // cout << "Go into the is_periodic_preprocessing function!" << endl;

    // Get all runs of S
    // string S(reinterpret_cast<const char*>(text_string), strlen(reinterpret_cast<const char*>(text_string)) - 1);
    // auto const R = linear_time_runs::compute_all_runs(S.data(), S.size());
    auto const R = linear_time_runs::compute_all_runs(text_string, text_size);
    int points_num = R.size();
    // cout << "\nString S contains " << points_num << " runs:" << endl;

    // Create an interval tree
    IntervalTree<int> tree;  
    for (auto run : R) {
      Interval<int> cur = {run.start, run.end};
      cur.per = run.period;
      tree.insert(cur);
      // cout << "start=" << run.start
      //      << ", end=" <<  run.end
      //      << ", per=" << run.period
      //      << ", len=" << run.length
      //      << ", exp=" << run.length / (double) run.period
      //      << ", str=" << S.substr(run.start, run.length) << endl;
    }

    return tree;
}


bool is_periodic(int I, int J, IntervalTree<int>& interval_tree, int &p) {
    // auto start = chrono::high_resolution_clock::now();    
    Interval<int> wantedInterval(I, J);
    const auto &outerIntervals = interval_tree.findOuterIntervals(wantedInterval);
    // auto end = chrono::high_resolution_clock::now();    
    // chrono::duration<double> elapsed = end - start;
    // interval_query_runtime = interval_query_runtime + elapsed.count();
    // sum_sel+=outerIntervals.size();
    // count_sel++;

    bool check_length = false;
    int tmp_p = J - I + 1;
    // Print all intervals
    // cout << "Outer intervals for " << wantedInterval << ":" << endl;
    for (const auto &interval : outerIntervals) {
        int per = interval.per;
        // cout << interval << ", per = " << per << endl;
        tmp_p = min(tmp_p, per);
    }

    // cout << "tmp_p = " << tmp_p << endl;
    if (tmp_p * 2 <= J - I + 1) {
      check_length = true;
      p = tmp_p;
    }

    return check_length;
}


int greedy(vector<int>& O, int t, int lamda) {
  // auto start = chrono::high_resolution_clock::now();

  // cout << "**********Into the Greedy function!**********" << endl;
  // if (t==1)
  //   return 1;
  int k_prime_prime = 0, O_size = O.size();
  // cout << "O_size = " << O_size << ", lamda = " << lamda << ", t = " << t << endl;
  for (int ell = 0; ell < O_size; ell++) {
    // cout << "The current ell = " << ell << endl;
    if (ell <= O_size - 2 && O[ell + 1] - O[ell] <= lamda - 1 && k_prime_prime < t) {
      // cout << "Kill a pair! O[ell + 1] = " << O[ell + 1] << ", O[ell] = " << O[ell] << endl;
      k_prime_prime ++;
      ell ++;
    }
  }
  int k_prime = t - k_prime_prime;
  // cout << "k_prime = " << k_prime << ", k_prime_prime = " << k_prime_prime << ", return value is " << k_prime + 2 * k_prime_prime << endl;
  // cout << "************Greedy function end*************" << endl;

  // auto end = chrono::high_resolution_clock::now();
  // chrono::duration<double> elapsed = end - start;
  // greedy_runtime = greedy_runtime + elapsed.count();
  
  return k_prime + 2 * k_prime_prime;
}


bool aperiodic_survive(STvertex* root, int* &suffix_array, int freq_threshold, int k, int l, int r, int I, int J) {
  int Occ = r - l + 1;
  // cout << "****************Into the aperiodic_survive function.**************" << endl;
  // cout << "The Occ is " << Occ << ", freq_threshold is " << freq_threshold << ", k is " << k << endl;
  if (Occ >= freq_threshold + 2 * k) {
    // cout << "Into Case 1" << endl;
    return true;
  }
  else if (Occ < freq_threshold + k) {
    // cout << "Into Case 2" << endl;
    return false;
  }
  else {
    vector<int> O;
    for (int i = l; i <= r; i++) {
      O.push_back(suffix_array[i]);
    }
    sort(O.begin(), O.end());
    // cout << "After sorting the O vector is ";
    // for (auto const &item : O) {
    //   cout << item << " ";
    // }
    // cout << endl;
    
    if (Occ - greedy(O, k, J - I + 1) >= freq_threshold) {
      // cout << "Into Case 3" << endl;
      return true;
    }
    else {
      // cout << "Into Case 4" << endl;
      return false;
    }
  }
}


vector<vector<int>> create_clusters(int* &suffix_array, int l, int r, int p, int max_H_size) {
  vector<int> O;
  for (int i = l; i <= r; i++) {
      O.push_back(suffix_array[i]);
  }
  sort(O.begin(), O.end());
  int O_size = O.size();
  // cout << "The size of O set is " << O_size << endl;
  // for (auto const &item : O) {
  //   cout << item << " ";
  // }
  // cout << endl;

  vector<vector<int>> H;
  vector<int> current_cluster;
  current_cluster.push_back(O[0]);
  for(int i = 1; i < O_size; i++) {
    // cout << "Current O[i] is " << O[i] << ", O[i - 1] is " << O[i - 1] << endl;
    if (O[i] - O[i - 1] != p) {
      H.push_back(current_cluster);
      current_cluster.clear();
      if (H.size() == max_H_size - 1) {
        // cout << "The number of clusters reaches the max_H_size " << max_H_size << ", stop iterating!" << endl;
        break;
      }
    }
    current_cluster.push_back(O[i]);
  }
  H.push_back(current_cluster);

  return H;
}

int ceilDivision(int a, int b) {
    return (a + b - 1) / b;
}


bool periodic_survive(int l, int r, int I, int J, int freq_threshold, int k, vector<vector<int>>& H, int p) {
  // cout << "****************Into the periodic_survive function.**************" << endl;
  int Occ = r - l + 1;
  // int alpha = (J - I + 1) / p;
  int alpha = ceilDivision(J - I + 1, p);
  // cout << "Occ = " << Occ << ", J - I + 1 = " << J - I + 1 << ", alpha = " << alpha << ", p = " << p << endl;

  vector<vector<int>> cal_C;
  for (auto const &C : H) {
    int C_size = C.size();
    int mod_num = C_size % alpha;
    // cout << "C_size = " << C_size << ", mod_num = " << mod_num << endl;
    if (mod_num == 1 || mod_num == 2) {
      cal_C.push_back(C);
    }
  }
  // cout << "Now check the cal_C:" << endl;
  // for(auto const &C : cal_C) {
  //   for (auto const &item : C) {
  //     cout << item << " ";
  //   }
  //   cout << endl;
  // }

  int cal_C_size = cal_C.size();
  // cout << "cal_C_size = " << cal_C_size << endl;
  vector<int> OV;
  OV.push_back(0);
  for (int i = 1; i < cal_C_size; i++) {
    // cout << "i = " << i << ", cal_C[i - 1].size() - 1 = " << cal_C[i - 1].size() - 1<< ", cal_C[i - 1][cal_C[i - 1].size() - 1] = " << cal_C[i - 1][cal_C[i - 1].size() - 1] << ", cal_C[i][0] = " << cal_C[i][0] << endl;
    // OV[i] = max(cal_C[i - 1][cal_C[i - 1].size() - 1] + J - I + 1 - cal_C[i][0], 0);
    OV.push_back(max(cal_C[i - 1][cal_C[i - 1].size() - 1] + J - I + 1 - cal_C[i][0], 0));
  }
  // cout << "Now check the value of OV: " << endl;
  // for (int i = 0; i < OV.size(); i++) {
  //   cout << OV[i] << " ";
  // }
  // cout << endl;

  vector<int> cal_C_prime;
  int curr = 0, i = 0; 
  priority_queue<int> cal_D;
  // cout << "**********Start to check |C| mod alpha!**********" << endl;
  for (auto const &C : H) {
    int C_size = C.size();
    int mod_num = C_size % alpha;
    // cout << "C_size = " << C_size << ", mod_num = " << mod_num << ", curr = " << curr << ", i = " << i << endl;
    if(mod_num == 0) {
      // cout << "Push to cal_D with mode = 0" << endl;
      cal_D.push(C_size);
    }
    else if(mod_num >= 3) {
      // cout << "Push to cal_D with mode = 3" << endl;

      cal_D.push(C_size - mod_num);
      cal_D.push(mod_num);
    }
    else if(mod_num == 1) {
      // cout << "Push to cal_D with mode = 1" << endl;
      int OV_value = OV[i];
      cal_D.push(C_size - 1);
      cal_C_prime.push_back(curr - OV_value);
      curr = curr - OV_value + J - I + 1;
      i++;
    }
    else if(mod_num == 2) {
      // cout << "Go into the case with mode = 2" << endl;
      // cout << "Push to cal_D with mode = 2" << endl;
      int OV_value = OV[i];
      cal_D.push(C_size - 2);
      cal_C_prime.push_back(curr - OV_value);
      cal_C_prime.push_back(curr - OV_value + p);
      curr = curr - OV_value + J - I + 1 + p;
      i++;
    }
  }
  sort(cal_C_prime.begin(), cal_C_prime.end());
  // cout << "After sorting the cal_C_prime vector is " << endl;
  // for (auto const &item : cal_C_prime) {
  //   cout << item << " ";
  // }
  // cout << endl;

  int t = k, K = 0;
  while (!cal_D.empty() && t >= ceilDivision(cal_D.top(), alpha)) {
    // cout << "cal_D.top() = " << cal_D.top() << ", (cal_D.top() + alpha - 1) / alpha = " << (cal_D.top() + alpha - 1) / alpha << ", t = " << t << endl;
    K = K + cal_D.top();
    t = t - ceilDivision(cal_D.top(), alpha);
    // t = t - max(1,ceilDivision(cal_D.top(), alpha));
    cal_D.pop();
  }
  // cout << "Now t = " << t << ", K = " << K << endl;
  if(cal_D.empty() && t > 0) {
    K = K + greedy(cal_C_prime, t, J - I + 1);
  }
  if(!cal_D.empty() && t < cal_D.top() / alpha) {
    // cout << "Go into the t * alpha case!" << endl;
    K = K + t * alpha;
  }

  if(Occ - K >= freq_threshold) {
    // cout << "RETURN Survive! Occ = " << Occ << ", K = " << K << ", freq_threshold = " << freq_threshold << endl;
    return true;
  }

  return false;
}


bool check_freq_periodic_survive(bool is_node_checking, bool &is_cut_point, STvertex* &r, STvertex* &current, int left, int right, int I, int J, int freq_threshold, int k, int* &suffix_array, IntervalTree<int>& interval_tree) {
  // cout << "current node's left = " << left << ", right = " << right << ", I = " << I << ", J = " << J << endl;
  // ofstream output_stream;
  // auto total_start = chrono::high_resolution_clock::now();
  // output_stream.open("FaS_runtime_detail", ofstream::out | ofstream::app);
  bool periodic_survive_value = false, aperiodic_survive_value = false;
  vector<STvertex*> current_path;
  vector<vector<int>> H;
  if (right - left + 1 >= freq_threshold) {   // This is a \tau-frequent node
    // cout << "This node is frequent!" << endl;
    int p = INT_MAX;
    // auto start = chrono::high_resolution_clock::now();
    bool is_periodic_value = is_periodic(I, J, interval_tree, p);  // Here p can store the return value from is_periodic when YES
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double> elapsed = end - start;
    // is_periodic_runtime = is_periodic_runtime + elapsed.count();
    // output_stream << "is_periodic:" << elapsed.count() << " ";
    
    // cout << "The value of is_periodic is " << is_periodic_value << ", the p = " << p << endl;
    if (is_periodic_value) {
      // is_periodic_yes ++;   // Count the times of answering YES
      // First create the clusters H
      int max_H_size = 2 * k + freq_threshold;
      // start = chrono::high_resolution_clock::now();
      H = create_clusters(suffix_array, left, right, p, max_H_size);
      // end = chrono::high_resolution_clock::now();
      // elapsed = end - start;
      // create_cluster_runtime = create_cluster_runtime + elapsed.count();
      // output_stream << "is_periodic=YES create_clusters:" << elapsed.count() << " ";

      // cout << "The clusters in the H are: " << endl;
      // for(auto const &C : H) {
      //   for(auto const &item : C) {
      //     cout << item << " ";
      //   }
      //   cout << endl;
      // }

      // Then call periodic_survive
      // start = chrono::high_resolution_clock::now();
      // cout << "Before into the periodic_survive, the p = " << p << endl;
      periodic_survive_value = periodic_survive(left, right, I, J, freq_threshold, k, H, p);
      // end = chrono::high_resolution_clock::now();
      // elapsed = end - start;
      // periodic_survive_runtime = periodic_survive_runtime + elapsed.count();

      // cout << "The value of periodic_survive is " << periodic_survive_value << endl;
      if (periodic_survive_value) {   // current is a node lying on the cut of ST
        if (is_node_checking) {   // Propagate upforward the status of frequent and survive to all ancestors except root
          // start = chrono::high_resolution_clock::now();
          is_cut_point = true;
          current->flag = true;
          current_path = current->path;
          int current_path_length = current_path.size();
          for (int i = 1; i < current_path_length; i++) {   // Do not include the root
            current_path[i]->flag = true;
          }
          // end = chrono::high_resolution_clock::now();
          // elapsed = end - start;
          // forward_runtime = forward_runtime + elapsed.count();
        }
      }
      
    }

    else {
      // is_periodic_no ++;   // Count the times of answering NO
      // start = chrono::high_resolution_clock::now();
      aperiodic_survive_value = aperiodic_survive(r, suffix_array, freq_threshold, k, left, right, I, J);
      // end = chrono::high_resolution_clock::now();
      // elapsed = end - start;
      // aperiodic_survive_runtime = aperiodic_survive_runtime + elapsed.count();

      // cout << "The value of aperiodic_survive is " << aperiodic_survive_value << endl;
      if (aperiodic_survive_value) {   // current is a node lying on the cut of ST
        if (is_node_checking) {   // Propagate upforward the status of frequent and survive to all ancestors except root
          // start = chrono::high_resolution_clock::now();
          is_cut_point = true;
          current->flag = true;
          current_path = current->path;
          int current_path_length = current_path.size();
          for (int i = 1; i < current_path_length; i++) {   // Do not include the root
            current_path[i]->flag = true;
          }
          // end = chrono::high_resolution_clock::now();
          // elapsed = end - start;
          // forward_runtime = forward_runtime + elapsed.count();
        }
      }
    }
  }
  // auto total_end = chrono::high_resolution_clock::now();
  // chrono::duration<double> elapsed = total_end - total_start;
  // check_freq_periodic_survive_runtime = check_freq_periodic_survive_runtime + elapsed.count();


  return (aperiodic_survive_value || periodic_survive_value);
}

int binary_search_longest_substring (int low, int high, int I, int child_l, int child_r, int freq_threshold, int k, bool &is_cut_point, STvertex* &root, STvertex* &current, int* &suffix_array, IntervalTree<int>& interval_tree) {
  if (child_r - child_l + 1 < freq_threshold) {   // If the child node is not frequent, continue to the next child
    return low;
  }

  int mid = 0, success_record = low;
  while (low < high) {
    mid = low + (high - low) / 2;     // mid is the floor int
    if (mid == low) {
      bool is_freq_survive = check_freq_periodic_survive(false, is_cut_point, root, current, child_l, child_r, I, high, freq_threshold, k, suffix_array, interval_tree);
      if (is_freq_survive) {
        success_record = high;
      }
      break;
    }

    // auto start = chrono::high_resolution_clock::now();
    // cout << "current low = " << low << ", high = " << high << ", mid = " << mid << endl;
    bool is_freq_survive = check_freq_periodic_survive(false, is_cut_point, root, current, child_l, child_r, I, mid, freq_threshold, k, suffix_array, interval_tree);
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double> elapsed = end - start;

    // cout << "the is_freq_survive result is " << is_freq_survive << endl;
    if (is_freq_survive) {
      low = mid;
      success_record = mid;
    }
    else {
      high = mid - 1;
    }
    // cout << "At the end of this loop of binary search,  low = " << low << ", high = " << high << ", success_record = " << success_record << endl; 
  }
  // cout << "OUT Binary search, low = " << low << ", high = " << high << ", mid = " << mid << endl; 

  return success_record;
}



int main(int argv, char** argc) {

    time_t before, after;
    int k, freq_threshold;
    string S;
    ofstream output_stream;

    if(argv < 4) {
      cout << "Usage: ./main [text_file] [freq_threshold] [number of letter substitions]" << endl;
      return 1;
    }
    // Input text file
    ifstream is_text;
    string text_file = argc[1];

     // Input frequency threshold (tau)
    freq_threshold = stoi(argc[2]); 
    // Input the number of positions about letter replacements in S
    k = stoi(argc[3]); 

    string output_file = "output/" + text_file + "_" + to_string(freq_threshold) + "_" + to_string(k);

    string text_file_path = "data/" + text_file;
    is_text.open (text_file_path, ios::in | ios::binary);
    
    ifstream in_file(text_file_path, ios::binary);
    in_file.seekg(0, ios::end);
    INT text_file_size = in_file.tellg();
    
    unsigned char * text_string = ( unsigned char * ) malloc (  ( text_file_size+4 ) * sizeof ( unsigned char ) );
    char chr = 0;
    INT text_size = 0;
    
    string runtime_detail_csv = "runtime_details.csv";
    output_stream.open(runtime_detail_csv, ios::app);
    output_stream << "text_file,tau,k,read_txt,create_ST,create_SA,create_intervals,is_periodic_preprocess,find_cut,total\n";
    // output_stream << "text_file,tau,k,total_runtime\n";
    output_stream << text_file << "," << to_string(freq_threshold) << "," << to_string(k) << ",";
    output_stream.close();

    // At the beginning and end of S, add two $ to ensure the all_run runs successfully!
    auto start = chrono::high_resolution_clock::now();
    text_string[0] = '\1';
    // cout << "text_file_size is " << text_file_size << ", start reading! " << endl;
    for (INT i = 1; i <= text_file_size; i++)
    {	
      is_text.read(reinterpret_cast<char*>(&chr), 1);
      text_string[i] = chr;
      // cout << "i=" << i << "," << chr << "(" << text_size << "),dec_value=" << (unsigned int)chr << "; ";
      text_size++;
    }
    is_text.close();
    // cout << endl;
    
    text_string[ text_size+1] = '\1';
    text_string[ text_size+2] = '\0';	// Change '~' to '!' to make the symbol's ascii is smaller than the chars in txt
    text_size = text_size + 2;  // Do not include the final \0
    cout << "Finish reading the text file!" << endl;
    // cout << "CHECK! The text_size = " << text_size << endl;
    // for(int i = 0; i < text_size; i++) {
    //   cout << "char:" << (unsigned int)text_string[i] << endl;
    // }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    output_stream.open(runtime_detail_csv, ios::app);
    output_stream << elapsed.count() << ",";
    output_stream.close();

    auto whole_start = chrono::high_resolution_clock::now();
    
    // Pre-processing begin
    start = chrono::high_resolution_clock::now();
    STvertex *r = Create_suffix_tree( text_string , text_size+1 );
    cout << "Create ST successfully! The number of leaves is " << liscie << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    output_stream.open(runtime_detail_csv, ios::app);
    output_stream << elapsed.count() << ",";
    output_stream.close();

    start = chrono::high_resolution_clock::now();
    int *suffix_array =(int*) malloc(sizeof(int) * text_size);
    build_suffix_array(suffix_array, text_size, r);
    cout << "Construct SA successfully!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    output_stream.open(runtime_detail_csv, ios::app);
    output_stream << elapsed.count() << ",";
    output_stream.close();
    // cout<<"Suffix Array for String ";
    // for(int i=0; i<text_size; i++)
    //     cout<<txt[i];
   	// cout<<" is: ";
    // for(int i=0; i<text_size; i++)
    //     cout<<suffix_array[i]<<" ";
    // cout<<endl;
    int *inv_suffix_array =(int*) malloc(sizeof(int) * text_size);
    for(int i=0; i<text_size; i++) {
      inv_suffix_array[suffix_array[i]] = i;
    }

    // interval_map: key is each node in ST, value is <l,r>, where [l,r] is corresponding SA interval of this node
    start = chrono::high_resolution_clock::now();
    vector<STvertex*> rev_bottomup_ordered_nodes = bottom_up_SA_interval(root, suffix_array, inv_suffix_array, text_size);
    cout << "Construct SA interval for each node in ST successfully. Preprocessing end!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    output_stream.open(runtime_detail_csv, ios::app);
    output_stream << elapsed.count() << ",";
    output_stream.close();
    free(inv_suffix_array);
    // Pre-processing end


    // Check if a substring is periodic, and return its period if it is periodic
    // Find all runs of S, and store it in a PST ippst
    start = chrono::high_resolution_clock::now();
    // InPlacePST ippst = is_periodic_preprocessing(text_string, text_size - 1);  // don't include the last char !
    IntervalTree<int> runs = is_periodic_preprocessing(text_string, text_size);
    cout << "Construct all runs successfully!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    output_stream.open(runtime_detail_csv, ios::app);
    output_stream << elapsed.count() << ",";
    output_stream.close();
    free(text_string);


    // Start MAIN ALGORITHM
    map<unsigned char,STedge,greater<unsigned char>> children_map;
	  STvertex* current = r;
    STvertex* child_node;
    int *OUTPUT =(int*) malloc(sizeof(int) * text_size);
    for (int i = 0; i < text_size; i++) {
      OUTPUT[i] = 0;
    }

	  cout << "Start to find the cut!" << endl;
    // cout << "The size of bottom_up_ordered_nodes is " << rev_bottomup_ordered_nodes.size() << ", text_size = " << text_size << endl;
    // Now, the nodes are in reverse post-order, so we need to process them in the correct order
    start = chrono::high_resolution_clock::now();
    double success_binary_search_runtime = 0, fail_binary_search_runtime = 0, check_FaS_runtime = 0, loop_runtime = 0, if_loop_runtime = 0, else_loop_runtime = 0, if_child_runtime = 0, is_cut_runtime = 0, else_remain_runtime = 0;
    int binary_search_count = 0, check_FaS_count = 0;
    for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
      // output_stream.open("FaS_runtime", ofstream::out | ofstream::app);
      current = *it;
      // auto loop_start = chrono::high_resolution_clock::now();
      bool is_cut_point = false, is_freq_survive = false;
      children_map = current->g;
      int current_str_depth = current->str_depth_of_N;
      if(current->flag) {   // This node is the ancestor of a cut node u
        // auto if_loop_start = chrono::high_resolution_clock::now();
        // auto inner_start = chrono::high_resolution_clock::now();
        // cout << "current node is already frequent and survive, continue to next current" << endl;
        // auto success_child_start = chrono::high_resolution_clock::now();
        for (auto const &child : children_map) {
          child_node = child.second.v;
          vector<int> child_SA_interval = child_node->SA_interval;
          int child_l = child_SA_interval[0], child_r = child_SA_interval[1];
          int child_str_depth = child_node->str_depth_of_N;
          
          // cout << "Current child's [l,r] is [" << child_l << "," << child_r << "]" << endl;

          if (child_node->flag) {
            continue;
          }
          else {    // This child node is v
            // auto if_child_start = chrono::high_resolution_clock::now();
            for (int i = child_l; i <= child_r; i++) {
              // auto success_child_setting_start = chrono::high_resolution_clock::now();
              int I = suffix_array[i], J; // left bound of the substring is fixed, we need to find out the right bound
              int low = I + current_str_depth - 1, high = I + child_str_depth - 1;
              // auto success_child_setting_end = chrono::high_resolution_clock::now();
              // elapsed = success_child_setting_end - success_child_setting_start;
              // success_child_setting_runtime = success_child_setting_runtime + elapsed.count();
              // START BINARY SEARCH for J
              // Initialization: low is the end position of node u (cut node), high is the end position of node v (child of u)
              // cout << "Binary search start! i= " << i << ", I = " << I << endl;
              // auto bs_start = chrono::high_resolution_clock::now();
              binary_search_count ++;
              J = binary_search_longest_substring(low, high, I, child_l, child_r, freq_threshold, k, is_cut_point, root, current, suffix_array, runs);
              // auto bs_end = chrono::high_resolution_clock::now();
              // chrono::duration<double> bs_elapsed = bs_end - bs_start;
              // success_binary_search_runtime = success_binary_search_runtime + bs_elapsed.count();

              // cout << "Binary search end! The refined cut [I, J] is [" << I << "," << J << "]" << endl;
              // cout << "The OUTPUT for index (suffix_array[i]) " << I << " is " <<  J - I + 1 << endl;
              // cout << "The u str_depth = " << current->str_depth_of_N << endl;
              OUTPUT[I] = J - I + 1;
            }
            // auto if_child_end = chrono::high_resolution_clock::now();
            // chrono::duration<double> if_child_elapsed = if_child_end - if_child_start;
            // if_child_runtime = if_child_runtime + if_child_elapsed.count();
          }
          
        }
        // auto success_child_end = chrono::high_resolution_clock::now();
        // chrono::duration<double> elapsed = success_child_end - success_child_start;
        // success_setting_runtime = success_setting_runtime + elapsed.count();

        // auto if_loop_end = chrono::high_resolution_clock::now();
        // chrono::duration<double> if_loop_elapsed = if_loop_end - if_loop_start;
        // if_loop_runtime = if_loop_runtime + if_loop_elapsed.count();
        // STDelete(child_node);
      }
      else {
        // auto else_loop_start = chrono::high_resolution_clock::now();
        // cout << "Start to find the first cut node!" << endl;
        // auto else_remain_start = chrono::high_resolution_clock::now();
        vector<int> current_SA_interval = current->SA_interval;
        int left = current_SA_interval[0], right = current_SA_interval[1];
        if (right - left + 1 < freq_threshold) {  // If the current node is not frequent, continue to the next current
          continue;
        }
        int I = suffix_array[left];
        int J = I + current_str_depth - 1;
        

        // auto fas_start = chrono::high_resolution_clock::now();
        // check_FaS_count ++;
        is_freq_survive = check_freq_periodic_survive(true, is_cut_point, r, current, left, right, I, J, freq_threshold, k, suffix_array, runs);
        // auto fas_end = chrono::high_resolution_clock::now();
        // chrono::duration<double> fas_elapsed = fas_end - fas_start;
        // check_FaS_runtime = check_FaS_runtime + fas_elapsed.count();

        
        if (is_cut_point) {
          // cout << "*********This is a cut node! Start binary search to find out the refined cut!********" << endl;
          is_freq_survive = false;
          for (auto const &child : children_map) {
            // auto fail_child_setting_start = chrono::high_resolution_clock::now();
            child_node = child.second.v;
            vector<int> child_SA_interval = child_node->SA_interval;
            int child_l = child_SA_interval[0], child_r = child_SA_interval[1];
            int child_str_depth = child_node->str_depth_of_N;
            
            // cout << "Current child's [l,r] is [" << child_l << "," << child_r << "]" << endl;
            for (int i = child_l; i <= child_r; i++) {
              // auto is_cut_start = chrono::high_resolution_clock::now();

              int I = suffix_array[i], J; // left bound of the substring is fixed, we need to find out the right bound
              int low = I + current_str_depth - 1, high = I + child_str_depth - 1;
              // START BINARY SEARCH for J
              // Initialization: low is the end position of node u (cut node), high is the end position of node v (child of u)
              // cout << "Binary search start! i= " << i << ", I = " << I << endl;
              // auto bs_start = chrono::high_resolution_clock::now();
              // binary_search_count ++;
              J = binary_search_longest_substring(low, high, I, child_l, child_r, freq_threshold, k, is_cut_point, root, current, suffix_array, runs);
              // auto bs_end = chrono::high_resolution_clock::now();
              // chrono::duration<double> bs_elapsed = bs_end - bs_start;
              // fail_binary_search_runtime = fail_binary_search_runtime + bs_elapsed.count();

              // auto is_cut_end = chrono::high_resolution_clock::now();
              // chrono::duration<double> is_cut_elapsed = is_cut_end - is_cut_start;
              // is_cut_runtime = is_cut_runtime + is_cut_elapsed.count();
              
              // cout << "Binary search end! The refined cut [I, J] is [" << I << "," << J << "]" << endl;
              // cout << "The OUTPUT for index (suffix_array[i]) " << I << " is " <<  J - I + 1 << endl;
              OUTPUT[I] = J - I + 1;
            }

            // auto fail_child_setting_end = chrono::high_resolution_clock::now();
            // elapsed = fail_child_setting_end - fail_child_setting_start;
            // fail_child_setting_runtime = fail_child_setting_runtime + elapsed.count();
          }
          
          // STDelete(child_node);
        }

        // auto else_loop_end = chrono::high_resolution_clock::now();
        // chrono::duration<double> else_loop_elapsed = else_loop_end - else_loop_start;
        // else_loop_runtime = else_loop_runtime + else_loop_elapsed.count();
      }

    // auto loop_end = chrono::high_resolution_clock::now();
    // chrono::duration<double> loop_elapsed = loop_end - loop_start;
    // loop_runtime = loop_runtime + loop_elapsed.count();
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  output_stream.open(runtime_detail_csv, ios::app);
  output_stream << elapsed.count() << ",";
  output_stream.close();

  // Clear suffix array, suffix tree and interval tree
  // for (const auto &node : rev_bottomup_ordered_nodes) {
  //   STDelete(node);
  // }
  free(suffix_array);
  STDelete(r);
  runs.clear();

  auto whole_end = chrono::high_resolution_clock::now();
  chrono::duration<double> whole_elapsed = whole_end - whole_start;
  cout << "The whole process takes " << whole_elapsed.count() << " s." << endl;
  output_stream.open(runtime_detail_csv, ios::app);
  output_stream << whole_elapsed.count() << "\n";
  output_stream.close();

  
  // output_stream.open(output_file);
  output_stream.open("main_output");
  if(!output_stream.is_open()) {
        cout << "Couldn't open output file\n" << endl; 
  }
  // cout << "The OUTPUT with size " << text_size - 2 << " is ";
  for(int i = 1; i < text_size - 1; i++) {  // Exclude the first and last special char
    // cout << OUTPUT[i] << " ";
    output_stream << OUTPUT[i] << "\n";
  }
  // cout << endl;
  output_stream.close();
  free(OUTPUT);


  cout << "Finish!\n" << endl;

  // cout << "In find_cut part, success_binary_search_runtime = " << success_binary_search_runtime << ", fail_binary_search_runtime = " << fail_binary_search_runtime << ", check_FaS_runtime = " << check_FaS_runtime << ", forward_runtime = " << forward_runtime << ", binary_search_count = " << binary_search_count << ", check_FaS_count = " << check_FaS_count << endl;
  // // cout << "Each binary search avg runtime = " << binary_search_runtime / (double) binary_search_count << ", each check FaS avg runtime = " << check_FaS_runtime / (double) check_FaS_count << endl;
  // cout << "The total_find_cut_runtime = " << loop_runtime << ", if_flag_SUCCESS = " << if_loop_runtime << ", if_flag_FAIL = " << else_loop_runtime << endl;
  // cout << "When SUCCESS, find refined cut = " << if_child_runtime << endl;
  // cout << "The children traverse in SUCCESS is " << success_setting_runtime << ", children setting is " << success_child_setting_runtime << endl;
  // cout << "\nWhen FAIL, check_FaS_runtime (first_cut) = " << check_FaS_runtime << endl;
  // cout << "In the refined cut, the children traverse = " << is_cut_runtime << ", children setting = " << fail_child_setting_runtime << endl;
  // // cout << "\nSpecific function: check_freq_periodic_survive_runtime = " << check_freq_periodic_survive_runtime << endl;
  // cout << "Specific function: is_periodic_runtime = " << is_periodic_runtime << ", aperiodic_survive_runtime = " << aperiodic_survive_runtime << ", periodic_survive_runtime = " << periodic_survive_runtime << ", create_clusters_runtime = " << create_cluster_runtime << ", greedy_runtime = " << greedy_runtime << endl;
  // // cout << "The runtime of constructing the interval tree is " << interval_tree_build_runtime << " s, the total runtime of querying on the interval tree is " << interval_query_runtime << " s." << endl;
  // cout << "The OUTPUT_runtime = " << OUTPUT_runtime << endl;
  // cout << "\nThe count of is_periodic_yes = " << is_periodic_yes << ", count of is_periodic_no = " << is_periodic_no << endl;

  

  

  return 0;
}