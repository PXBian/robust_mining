#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <limits>
#include <cstring>
#include <vector>
#include <fstream>
#include <stack>
#include <algorithm>
#include <chrono>
#include "PSTPoint.h"
#include "InPlacePST.h"
#include "array_utilities.h"
#include "control_utilities.h"
#include "runs.hpp"

using namespace std;
using namespace PrioritySearchTree;
typedef int64_t INT;

#define FOR(I, A, B) for (INT I = (A); I <= (B); I++)
#define FORD(I, A, B) for (INT I = (A); I >= (B); I--)
#define REP(I, N) for (INT I = 0; I < (N); I++)
#define VAR(V, init) __typeof(init) V = (init)
#define FORE(I, C) for (VAR(I, (C).begin()); I != (C).end(); I++)


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

// vector<STvertex*> find_branch_frequent_and_build_SA(STvertex* r, int freq_threshold, unsigned char *x, int* suffix_array, int txt_size) {
// 	map<STvertex*, pair<vector<STvertex*>, int>> nonleaf_info;
// 	vector<pair<STvertex*, bool>> nonleaf_insert_order;	// Record the DFS order and whether check propagating upward
// 	vector<STvertex*> branching_frequent_nodes;

// 	STvertex* R = r;
// 	vector<STvertex*> path;
// 	path.push_back(R);
// 	pair<STvertex*, vector<STvertex*>> current_stack_item = make_pair(R, path);
// 	stack<pair<STvertex*, vector<STvertex*>>> dfs_stack;	// first is the current node, second is its path
// 	dfs_stack.push(current_stack_item);

// 	int idx = 0;
// 	int cnt = 1;
// 	// Use DFS to traverse every node in the suffix tree
// 	while(!dfs_stack.empty()) {
// 		cout << "--------This is the " << cnt << " loop!-------" << endl;
// 		current_stack_item = dfs_stack.top();
// 		dfs_stack.pop();
// 		STvertex* current_node = current_stack_item.first;
// 		vector<STvertex*> current_path = current_stack_item.second;
// 		map<unsigned char,STedge,greater<unsigned char>> children_map = current_node->g;

// 		if(current_node->numer > -1 && current_node->numer < txt_size) {	// current_node is a leaf
// 			// Get its father from the path in the map
// 			// father.number_of_leaves ++; 
// 			// AT THIS STEP,first ignore its other ancestors, just record the number of "direct" leaves
// 			cout << "This is a leaf" << endl;
// 			cout << "The numer of this leaf is " << current_node->numer << endl;
// 			STvertex* leaf_father = current_path[current_path.size() - 2];
// 			nonleaf_info[leaf_father].second++;


// 			suffix_array[idx] = current_node->numer;
// 			idx ++;
// 		}
// 		else {
// 			// Record the branching nodes
// 			// if (current_node != R && children_map.size() > 1) {
// 			// 	branching_nodes.push_back(current_node);
// 			// }

// 			// Initialize the nonleaf_info
// 			pair<vector<STvertex*>, int> node_info = make_pair(current_path, 0);
// 			nonleaf_info.insert({current_node, node_info});
// 			nonleaf_insert_order.push_back(make_pair(current_node, false));
			
// 			for (auto const &child : children_map) {
// 				STvertex* child_node = child.second.v;
// 				vector<STvertex*> child_path = current_path;
// 				child_path.push_back(child_node);
// 				dfs_stack.push(make_pair(child_node, child_path));
// 				// Print the current child's info on edge
// 				// Print_edge(child.second, x);
// 			}
// 		}

// 		cnt++;
// 	}

// 	cout << "--------------End of DFS traverse!---------------" << endl;
// 	cout << "--------------Start to construct frequent nodes!---------------" << endl;

// 	// Traverse all nonleaf nodes and search for the frequent nodes
// 	for (int i = nonleaf_insert_order.size() - 1; i >= 0; i--) {	
// 		if(nonleaf_insert_order[i].second) {	// TRUE: This node has satisfied the frequent threshold
// 			continue;
// 		}
// 		STvertex* check_node = nonleaf_insert_order[i].first;
// 		vector<STvertex*> node_path = nonleaf_info[nonleaf_insert_order[i].first].first;
// 		// cout << "The size of node path is " << node_path.size() << endl;
// 		// cout << "The number of leaves of this node is " << nonleaf_info[check_node].second << endl;
// 		if(nonleaf_info[check_node].second >= freq_threshold) {	// check_node is frequent: push_back all its ancestors to frequent_nodes
// 			for (int j = 1; j < node_path.size(); j++) {		// Skip the position 0 (root in suffix tree is not an ancestor)
// 				if(!nonleaf_insert_order[i].second) {			// FALSE: hasn't reached the frequent threshold
// 					if (node_path[j]->g.size() > 1) {
// 						branching_frequent_nodes.push_back(node_path[j]);	// j marks the positions of ancestors
// 					}
// 					nonleaf_insert_order[i].second = true;
// 				}
				
// 			}
// 		}
// 		else {		// check_node is infrequent: update its leaves' number to its father 
// 			STvertex* node_father = node_path[node_path.size() - 2];
// 			nonleaf_info[node_father].second += nonleaf_info[check_node].second;
// 		}

// 	}

// 	return branching_frequent_nodes;
// }


void neighborInterval(vector<vector<int>> &original_intervals, vector<vector<int>> &merged_intervals) {
  // Sort intervals based on start values
  sort(original_intervals.begin(), original_intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
  });

  stack<vector<int>> mergedStack;
  mergedStack.push(original_intervals[0]);

  for (int i = 1; i < original_intervals.size(); i++) {
    vector<int> current = original_intervals[i];
    vector<int>& top = mergedStack.top();
    if (current[0] - 1 == top[1]) {
        // If current interval is the neighbor of the top of the stack, merge them
        top[1] = max(top[1], current[1]);
    } else {
        // If no neighbor, push the current interval onto the stack
        mergedStack.push(current);
    }
  }

  // Convert the stack to a vector
  // vector<vector<int>> mergedIntervals;
  while (!mergedStack.empty()) {
      merged_intervals.insert(merged_intervals.begin(), mergedStack.top());
      mergedStack.pop();
  }
}


void bottom_up_SA_interval(STvertex* r, int* suffix_array, int* inv_suffix_array, int txt_size, vector<STvertex*>& bottom_up_ordered_nodes) {
	cout << "The sizeof suffix array is " << txt_size << endl;
	// map<STvertex*,vector<int>> interval_map;
  // ofstream output_stream;

	// Stack for traversing the tree
  stack<STvertex*> DFS_stack;
  // Stack to store the post-order traversal (in reverse order)
  stack<STvertex*> bottom_up_stack;
	map<unsigned char,STedge,greater<unsigned char>> children_map;
	STvertex* current = r;
  vector<STvertex*> path;

  // Start with the root node
  DFS_stack.push(current);
  path.push_back(current);
  current->path = path;
  current->str_depth_of_N = 0;
  // path_map.insert({current, make_pair(path, 0)});
  // Traverse the tree using DFS & bottom-up
  cout << "Start DFS traverse!" << endl;
  
  // ofstream output_file;
  // output_stream.open("DFS_runtime", ofstream::out | ofstream::app);
  // if(!output_file.is_open()) {
  //       cout << "Couldn't open output file\n" << endl; 
  //      // return exit(1);
  // }
  auto start = chrono::high_resolution_clock::now();
  while (!DFS_stack.empty()) {
    current = DFS_stack.top();
    DFS_stack.pop();

    current->flag = false;
    vector<STvertex*> current_path = current->path;
    int current_str_depth = current->str_depth_of_N;

	  children_map = current->g;
	  bool is_root = current == r;
	  cout << "In the DFS traverse, the current.numer is " << current->numer << ", it is root " << is_root << endl;

    vector<int> current_interval;
	  if(current->numer > -1 && current->numer < txt_size) {	// current is a leaf
      // getting index to SA from invSA
      int current_idx = inv_suffix_array[current->numer];
      // Initialize the interval of the current node (leaf)
      
      current_interval.push_back(current_idx);
      current_interval.push_back(current_idx);
      // cout << "The current_idx of this leaf is " << current_idx << endl;

      // interval_map.insert(make_pair(current, current_interval));
    }
    current->SA_interval = current_interval;

	  // Push all the children to the traversal stack (in the order they appear)
	  for (auto const &child : children_map) {
      STvertex* child_node = child.second.v;
      DFS_stack.push(child_node);
      int child_edge_length = child.second.r - child.second.l + 1;
      // // Print the current child's info on edge
      // Print_edge(child.second, text_string);
      int child_str_depth = current_str_depth + child_edge_length;
      // cout << "The numer of child_node is" << child_node->numer << ", the child_edge_length is " << child_edge_length << ", the child_str_depth is " << child_str_depth << endl; 
      vector<STvertex*> child_path = current_path;
      child_path.push_back(child_node);
      // cout << "After push the child_node to the path, the child_path is " << endl;
      // for (const auto &node : child_path) {
      //   cout << node->numer << " ";
      // }
      // cout << endl;
      child_node->path = child_path;
      child_node->str_depth_of_N = child_str_depth;
      // path_map.insert({child_node, make_pair(child_path, child_str_depth)});
    }
    // Push the current node to the result stack: Don't push the root, as well as the special char $
    if (!is_root && current->numer < txt_size) {
      bottom_up_stack.push(current);
      // cout << "Now push the " << current->numer << " into the result_stack!" << endl;
    }

	  // cout << "***********************" << endl;
	  // After this bottom-up traverse finished, only the leaves has records in the interval_map
  }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = end - start;
  // output_stream << elapsed.count() << " ";

	cout << "****************************************" << endl;

	cout << "End DFS traverse, start bottom-up traverse!" << endl;
  start = chrono::high_resolution_clock::now();
  // Now, the nodes are in reverse post-order, so we need to process them in the correct order
  while (!bottom_up_stack.empty()) {
    current = bottom_up_stack.top();
    bottom_up_ordered_nodes.push_back(current);
    bottom_up_stack.pop();
    cout << "Now enter the bottom-up loop, the current->numer is " << current->numer << endl;

    // if(interval_map.find(current) == interval_map.end()) {	// Didn't find out the record node in interval_map
    if(current->SA_interval.size() == 0) {
      cout << "Didn't find out the record in interval_map" << endl;
      children_map = current->g;
      vector<vector<int>> original_intervals, merged_intervals;
      for (auto const &child : children_map) {
        // vector<int> child_interval = interval_map.at(child.second.v);
        vector<int> child_interval = child.second.v->SA_interval;
        original_intervals.push_back(child_interval);
      }

      neighborInterval(original_intervals, merged_intervals);
      cout << "The merged_intervals is " << endl;
      for (auto const &interval : merged_intervals) {
        cout << interval[0] << "," << interval[1] << " ";
      }
      cout << endl;
      // interval_map.insert(make_pair(current, merged_intervals[0]));
      current->SA_interval = merged_intervals[0];
    }
    else{		// Has record
      // vector<int> cur_interval = interval_map.at(current);
      cout << "The current interval is " << current->SA_interval[0] << "," << current->SA_interval[1] << endl;
    }
  }
  end = chrono::high_resolution_clock::now();

	elapsed = end - start;
  // output_stream << elapsed.count() << "\n";
  // output_stream.close();
	// return interval_map;
}


struct PSTPointCompare
{
   bool operator() (const PSTPoint& lhs, const PSTPoint& rhs) const
   {
       return lhs.getX() < rhs.getX();
   }
};

InPlacePST is_periodic_preprocessing(unsigned char * text_string, int text_size, map<PSTPoint, int, PSTPointCompare>& per_map) {
    time_t before, after;
    const int MAX_POINTS_DISPLAY = 20;
    cout << "Go into the is_periodic_preprocessing function!" << endl;

    // Get all runs of S
    string S(reinterpret_cast<const char*>(text_string), strlen(reinterpret_cast<const char*>(text_string)) - 1);
    cout << "Before all_run, the S is " << S << ", the size of S is " << S.size() << endl;

    auto const R = linear_time_runs::compute_all_runs(S.data(), S.size());
    int points_num = R.size();
    cout << "\nString " << S << " contains " << points_num << " runs:" << endl;

    before = time(0);
    PSTPoint *points = new PSTPoint[points_num]; // allocate on the heap, start from position 1

    int point_idx = 0;
    for (auto run : R) {
      PSTPoint p(run.start,run.end); // allocate on the stack
      points[point_idx] = p;
      per_map.insert(make_pair(p, run.period));
      cout << "start=" << run.start
           << ", end=" <<  run.end
           << ", per=" << run.period
           << ", len=" << run.length
           << ", exp=" << run.length / (double) run.period
           << ", str=" << S.substr(run.start, run.length) << endl;
      point_idx++;
    }
    after = time(0);
    cout << "took: " << (after - before) << endl;
    if(points_num <= MAX_POINTS_DISPLAY) {
      cout << "Points: ";
      PSTArray::print(points,points_num);
    }
    
    /////////////////////////////////////////////////////////////////////////////
    // Build tree                                                              //
    /////////////////////////////////////////////////////////////////////////////
    cout << "Building tree..." << flush;
    before = time(0);
    InPlacePST ippst(points,points_num);
    after = time(0);
    cout << "took: " << (after - before) << endl;
    delete points;
    /////////////////////////////////////////////////////////////////////////////
    // Calculate memory usage                                                  //
    /////////////////////////////////////////////////////////////////////////////
    cout << "Memory usage: " << (points_num * sizeof(int)) << " bytes." << endl;

    return ippst;
}

bool is_periodic(int I, int J, InPlacePST& ippst, int &p, map<PSTPoint, int, PSTPointCompare>& per_map) {
    time_t before, after;
    int xmin = 0, xmax = 0, ymin = 0, ymax = 0;

    vector<PSTPoint>* R_results;
    // cout << ei << " iterations of ";
    cout << "Start to query ..." << endl;
    before = time(0);
    xmin = numeric_limits<int>::min(), xmax = I, ymin = J;
    R_results = ippst.enumerate3SidedUp(xmin,xmax,ymin);

    bool check_length = false;
    int tmp_p = J - I + 1;
    for (const PSTPoint& point : *R_results) {
      cout << "PSTPoint(x: " << point.getX() << ", y: " << point.getY() << "), its per is " << per_map[point] << endl;
      tmp_p = min(tmp_p, per_map[point]);
    }
    // cout << "The query check result is " << check_length << endl;
    if (tmp_p * 2 <= J - I + 1) {
        check_length = true;
        p = tmp_p;
    }

    delete R_results;
    // }
    after = time(0);
    cout << "took: " << (after - before) << endl;

    return check_length;
}

// vector<int> search_target_substr_in_ST(STvertex* root, map<STvertex*,vector<int>> interval_map, int I, int J, string target_string) {
//   vector<int> target_interval;
//   int search_idx = 0;
//   while (true) {

//   }

//   return target_interval;
// }


int greedy(vector<int> O, int t, int lamda) {
  cout << "**********Into the Greedy function!**********" << endl;
  // if (t==1)
  //   return 1;
  int k_prime_prime = 0, O_size = O.size();
  cout << "O_size = " << O_size << ", lamda = " << lamda << ", t = " << t << endl;
  for (int ell = 0; ell < O_size; ell++) {
    cout << "The current ell = " << ell << endl;
    if (ell <= O_size - 2 && O[ell + 1] - O[ell] <= lamda - 1) {
      cout << "Kill a pair! O[ell + 1] = " << O[ell + 1] << ", O[ell] = " << O[ell] << endl;
      k_prime_prime ++;
      ell ++;
    }
  }
  int k_prime = t - k_prime_prime;
  cout << "k_prime = " << k_prime << ", k_prime_prime = " << k_prime_prime << ", return value is " << k_prime + 2 * k_prime_prime << endl;
  cout << "************Greedy function end*************" << endl;
  
  return k_prime + 2 * k_prime_prime;
}

bool aperiodic_survive(STvertex* root, int* suffix_array, int freq_threshold, int k, int l, int r, int I, int J) {

  int Occ = r - l + 1;
  cout << "****************Into the aperiodic_survive function.**************" << endl;
  cout << "The Occ is " << Occ << ", freq_threshold is " << freq_threshold << ", k is " << k << endl;
  if (Occ >= freq_threshold + 2 * k) {
    cout << "Into Case 1" << endl;
    return true;
  }
  else if (Occ < freq_threshold + k) {
    cout << "Into Case 2" << endl;
    return false;
  }
  else {
    vector<int> O;
    for (int i = l; i <= r; i++) {
      O.push_back(suffix_array[i]);
    }
    sort(O.begin(), O.end());
    cout << "After sorting the O vector is ";
    for (auto const &item : O) {
      cout << item << " ";
    }
    cout << endl;
    

    if (Occ - greedy(O, k, J - I + 1) >= freq_threshold) {
      cout << "Into Case 3" << endl;
      return true;
    }
    else {
      cout << "Into Case 4" << endl;
      return false;
    }
  }
}


vector<vector<int>> create_clusters(int* suffix_array, int l, int r, int p, int max_H_size) {
  vector<int> O;
  for (int i = l; i <= r; i++) {
      O.push_back(suffix_array[i]);
  }
  sort(O.begin(), O.end());
  cout << "The size of O set is " << O.size() << endl;
  for (auto const &item : O) {
    cout << item << " ";
  }
  cout << endl;

  vector<vector<int>> H;
  vector<int> current_cluster;
  current_cluster.push_back(O[0]);
  for(int i = 1; i < O.size(); i++) {
    // cout << "Current O[i] is " << O[i] << ", O[i - 1] is " << O[i - 1] << endl;
    if (O[i] - O[i - 1] != p) {
      H.push_back(current_cluster);
      current_cluster.clear();
      if (H.size() == max_H_size - 1) {
        cout << "The number of clusters reaches the max_H_size " << max_H_size << ", stop iterating!" << endl;
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
  cout << "****************Into the periodic_survive function.**************" << endl;
  int Occ = r - l + 1;
  int alpha = (J - I + 1) / p;
  cout << "Occ = " << Occ << ", J - I + 1 = " << J - I + 1 << ", alpha = " << alpha << ", p = " << p << endl;

  vector<vector<int>> cal_C;
  for (auto const &C : H) {
    int C_size = C.size();
    int mod_num = C_size % alpha;
    cout << "C_size = " << C_size << ", mod_num = " << mod_num << endl;
    if (mod_num == 1 || mod_num == 2) {
      cal_C.push_back(C);
    }
  }
  cout << "Now check the cal_C:" << endl;
  for(auto const &C : cal_C) {
    for (auto const &item : C) {
      cout << item << " ";
    }
    cout << endl;
  }

  int cal_C_size = cal_C.size();
  cout << "cal_C_size = " << cal_C_size << endl;
  int *OV =(int*) malloc(sizeof(int) * (cal_C_size));
  OV[0] = 0;
  for (int i = 1; i < cal_C_size; i++) {
    cout << "i = " << i << ", cal_C[i - 1].size() - 1 = " << cal_C[i - 1].size() - 1<< ", cal_C[i - 1][cal_C[i - 1].size() - 1] = " << cal_C[i - 1][cal_C[i - 1].size() - 1] << ", cal_C[i][0] = " << cal_C[i][0] << endl;
    OV[i] = max(cal_C[i - 1][cal_C[i - 1].size() - 1] + J - I + 1 - cal_C[i][0], 0);
  }
  cout << "Now check the value of OV: " << endl;
  for (int i = 0; i < cal_C_size; i++) {
    cout << OV[i] << " ";
  }
  cout << endl;

  vector<int> cal_C_prime;
  int curr = 0, i = 0; 
  priority_queue<int> cal_D;
  cout << "**********Start to check |C| mod alpha!**********" << endl;
  for (auto const &C : H) {
    int C_size = C.size();
    int mod_num = C_size % alpha;
    cout << "C_size = " << C_size << ", mod_num = " << mod_num << ", curr = " << curr << ", i = " << i << endl;
    if(mod_num == 0) {
      cout << "Push to cal_D with mode = 0" << endl;
      cal_D.push(C_size);
    }
    else if(mod_num >= 3) {
      cout << "Push to cal_D with mode = 3" << endl;

      cal_D.push(C_size - mod_num);
      cal_D.push(mod_num);
    }
    else if(mod_num == 1) {
      cout << "Push to cal_D with mode = 1" << endl;
      cal_D.push(C_size - 1);
      cal_C_prime.push_back(curr - OV[i]);
      curr = curr - OV[i] + J - I + 1;
      i++;
    }
    else if(mod_num == 2) {
      cout << "Go into the case with mode = 2" << endl;
      cout << "Push to cal_D with mode = 2" << endl;
      cal_D.push(C_size - 2);
      cal_C_prime.push_back(curr - OV[i]);
      cal_C_prime.push_back(curr - OV[i] + p);
      curr = curr - OV[i] + J - I + 1 + p;
      i++;
    }
  }
  sort(cal_C_prime.begin(), cal_C_prime.end());
  cout << "After sorting the cal_C_prime vector is " << endl;
  for (auto const &item : cal_C_prime) {
    cout << item << " ";
  }
  cout << endl;

  int t = k, K = 0;
  while (!cal_D.empty() && t >= ceilDivision(cal_D.top(), alpha)) {
    // cout << "cal_D.top() = " << cal_D.top() << ", (cal_D.top() + alpha - 1) / alpha = " << (cal_D.top() + alpha - 1) / alpha << ", t = " << t << endl;
    K = K + cal_D.top();
    t = t - ceilDivision(cal_D.top(), alpha);
    cal_D.pop();
  }
  cout << "Now t = " << t << ", K = " << K << endl;
  if(cal_D.empty() && t > 0) {
    K = K + greedy(cal_C_prime, t, J - I + 1);
  }
  if(!cal_D.empty() && t < cal_D.top() / alpha) {
    K = K + t * alpha;
  }
  if(Occ - K >= freq_threshold) {
    cout << "RETURN Survive! Occ = " << Occ << ", K = " << K << ", freq_threshold = " << freq_threshold << endl;
    return true;
  }

  return false;
}


bool check_freq_periodic_survive(bool is_node_checking, bool &is_cut_point, STvertex* r, STvertex* current, int left, int right, int I, int J, int freq_threshold, int k, int* suffix_array, InPlacePST& ippst, map<PSTPoint, int, PSTPointCompare>& per_map) {
  cout << "current node's left = " << left << ", right = " << right << ", I = " << I << ", J = " << J << endl;
  // ofstream output_stream;
  auto total_start = chrono::high_resolution_clock::now();
  // output_stream.open("FaS_runtime_detail", ofstream::out | ofstream::app);
  bool periodic_survive_value = false, aperiodic_survive_value = false;
  if (right - left + 1 >= freq_threshold) {   // This is a \tau-frequent node
    cout << "This node is frequent!" << endl;
    int p = 1000000;
    auto start = chrono::high_resolution_clock::now();
    bool is_periodic_value = is_periodic(I, J, ippst, p, per_map);  // Here p can store the return value from is_periodic when YES
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    // output_stream << "is_periodic:" << elapsed.count() << " ";
    
    cout << "The value of is_periodic_value is " << is_periodic_value << ", the p = " << p << endl;
    if (is_periodic_value) {
      // First create the clusters H
      int max_H_size = 2 * k + freq_threshold;
      start = chrono::high_resolution_clock::now();
      vector<vector<int>> H = create_clusters(suffix_array, left, right, p, max_H_size);
      end = chrono::high_resolution_clock::now();
      elapsed = end - start;
      // output_stream << "is_periodic=YES create_clusters:" << elapsed.count() << " ";

      cout << "The clusters in the H are: " << endl;
      for(auto const &C : H) {
        for(auto const &item : C) {
          cout << item << " ";
        }
        cout << endl;
      }

      // Then call periodic_survive
      start = chrono::high_resolution_clock::now();
      periodic_survive_value = periodic_survive(left, right, I, J, freq_threshold, k, H, p);
      end = chrono::high_resolution_clock::now();
      elapsed = end - start;
      // output_stream << "periodic_survive:" << elapsed.count() << " ";
      cout << "The value of periodic_survive_value is " << periodic_survive_value << endl;
      if (periodic_survive_value) {   // current is a node lying on the cut of ST
        if (is_node_checking) {   // Propagate upforward the status of frequent and survive to all ancestors except root
          is_cut_point = true;
          current->flag = true;
          vector<STvertex*> current_path = current->path;
          for (int i = 1; i < current_path.size(); i++) {   // Do not include the root
            current_path[i]->flag = true;
          }
        }
      }
    }

    else {
      start = chrono::high_resolution_clock::now();
      aperiodic_survive_value = aperiodic_survive(r, suffix_array, freq_threshold, k, left, right, I, J);
      end = chrono::high_resolution_clock::now();
      elapsed = end - start;
      // output_stream << "periodic_survive:" << elapsed.count() << " ";
      cout << "The value of aperiodic_survive_result is " << aperiodic_survive_value << endl;
      if (aperiodic_survive_value) {   // current is a node lying on the cut of ST
        if (is_node_checking) {   // Propagate upforward the status of frequent and survive to all ancestors except root
          is_cut_point = true;
          current->flag = true;
          vector<STvertex*> current_path = current->path;
          for (int i = 1; i < current_path.size(); i++) {   // Do not include the root
            current_path[i]->flag = true;
          }
        }
      }
    }
  }
  auto total_end = chrono::high_resolution_clock::now();
  chrono::duration<double> elapsed = total_end - total_start;
  // output_stream << "Total:" << elapsed.count() << "\n";
  // output_stream.close();

  return (aperiodic_survive_value || periodic_survive_value);
}

int binary_search_longest_substring (int low, int high, int I, int child_l, int child_r, int freq_threshold, int k, bool &is_cut_point, STvertex* root, STvertex* current, int* suffix_array, InPlacePST& ippst, map<PSTPoint, int, PSTPointCompare>& per_map) {
  int mid = 0, success_record = low;
  while (low < high) {
    mid = low + (high - low) / 2;     // mid is the floor int
    if (mid == low) {
      break;
    }
    cout << "current low = " << low << ", high = " << high << ", mid = " << mid << endl;
    bool is_freq_survive = check_freq_periodic_survive(false, is_cut_point, root, current, child_l, child_r, I, mid, freq_threshold, k, suffix_array, ippst, per_map);
    cout << "the is_freq_survive result is " << is_freq_survive << endl;
    if (is_freq_survive) {
      low = mid;
      success_record = mid;
    }
    else {
      high = mid - 1;
    }
  }
  cout << "OUT Binary search, low = " << low << ", high = " << high << ", mid = " << mid << endl; 

  return success_record;
}




int main(int argv, char** argc) {
    time_t before, after;
    int k, freq_threshold;
    string S;
    ofstream output_stream;
    /////////////////////////////////////////////////////////////////////////////
    // Seed the PRNG                                                           //
    /////////////////////////////////////////////////////////////////////////////
    srand( time(0) );
    /////////////////////////////////////////////////////////////////////////////
    // Ensure the user has entered required parameters, otherwise print        //
    // a helpful message and bail out.                                         //
    /////////////////////////////////////////////////////////////////////////////
    if(argv < 4) {
      cout << "Usage: ./main [text_file] [freq_threshold] [number of letter substitions]" << endl;
      return 1;
    }
    // Input text file
    ifstream is_text;
    string text_file = argc[1];
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
    output_stream << "read_txt,create_ST,create_SA,create_intervals,is_periodic_preprocess,find_cut\n";

    // At the beginning and end of S, add two $ to ensure the all_run runs successfully!
    auto start = chrono::high_resolution_clock::now();
    text_string[0] = '$';
    cout << "text_file_size is " << text_file_size << ", start reading! " << endl;
    for (INT i = 1; i < text_file_size; i++)
    {	
      is_text.read(reinterpret_cast<char*>(&chr), 1);

      text_string[i] = chr;
      text_size++;
      // cout << chr << "(" << text_size << ") ";
    }
    is_text.close();
    // cout << endl;
    
    text_string[ text_size+1] = '$';
    text_string[ text_size+2] = '!';	// Change '~' to '!' to make the symbol's ascii is smaller than the chars in txt
    text_string[ text_size+3] = '\0';
    text_size = text_size + 2;  // Do not include the final ! 
    cout << "The text_size = " << text_size << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    output_stream << elapsed.count() << ",";
    
    
    // Input frequency threshold (tau)
    freq_threshold = stoi(argc[2]); 
    // Input the number of positions about letter replacements in S
    k = stoi(argc[3]); 

    string output_file = "output/" + text_file + "_" + to_string(freq_threshold) + "_" + to_string(k);


    // Pre-processing begin
    start = chrono::high_resolution_clock::now();
    STvertex *r = Create_suffix_tree( text_string , text_size+1 );
    cout << "Create ST successfully! The number of leaves is " << liscie << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    output_stream << elapsed.count() << ",";

    start = chrono::high_resolution_clock::now();
    int *suffix_array =(int*) malloc(sizeof(int) * text_size);
    build_suffix_array(suffix_array, text_size, r);
    cout << "Construct SA successfully!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    output_stream << elapsed.count() << ",";
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
    vector<STvertex*> bottom_up_ordered_nodes;
    bottom_up_SA_interval(root, suffix_array, inv_suffix_array, text_size, bottom_up_ordered_nodes);
    cout << "Construct SA interval for each node in ST successfully. Preprocessing end!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    output_stream << elapsed.count() << ",";
    // Pre-processing end


    // Check if a substring is periodic, and return its period if it is periodic
    // Find all runs of S, and store it in a PST ippst
    start = chrono::high_resolution_clock::now();
    map<PSTPoint, int, PSTPointCompare> per_map;
    InPlacePST ippst = is_periodic_preprocessing(text_string, text_size - 1, per_map);  // don't include the last char !
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    output_stream << elapsed.count() << ",";
    

    // Start MAIN ALGORITHM
    map<unsigned char,STedge,greater<unsigned char>> children_map;
	  STvertex* current = r;
    int *OUTPUT =(int*) malloc(sizeof(int) * text_size);
    for (int i = 0; i < text_size; i++) {
      OUTPUT[i] = 0;
    }

	  cout << "*****************Start bottom-up traverse!*****************" << endl;
    cout << "The size of bottom_up_ordered_nodes is " << bottom_up_ordered_nodes.size() << ", text_size = " << text_size << endl;
    // Now, the nodes are in reverse post-order, so we need to process them in the correct order
    start = chrono::high_resolution_clock::now();
    for (const auto &current : bottom_up_ordered_nodes) {
      auto total_start = chrono::high_resolution_clock::now();

      bool is_cut_point = false, is_freq_survive = false;
      children_map = current->g;
      if(current->flag) {   // This node is the ancestor of a cut node u
        cout << "current node is already frequent and survive, continue to next current" << endl;
        for (auto const &child : children_map) {
          STvertex* child_node = child.second.v;
          int child_l = child_node->SA_interval[0], child_r = child_node->SA_interval[1];
          cout << "Current child's [l,r] is [" << child_l << "," << child_r << "]" << endl;

          if (child_node->flag) {
            continue;
          }
          else {    // This child node is v
            for (int i = child_l; i <= child_r; i++) {
              int I = suffix_array[i], J; // left bound of the substring is fixed, we need to find out the right bound
            //   int low = I + path_map[current].second - 1, high = I + path_map[child_node].second - 1;
              int low = I + current->str_depth_of_N - 1, high = I + child_node->str_depth_of_N - 1;
              // START BINARY SEARCH for J
              // Initialization: low is the end position of node u (cut node), high is the end position of node v (child of u)
              cout << "Binary search start! i= " << i << ", I = " << I << endl;
              J = binary_search_longest_substring(low, high, I, child_l, child_r, freq_threshold, k, is_cut_point, root, current, suffix_array, ippst, per_map);

              cout << "Binary search end! The refined cut [I, J] is [" << I << "," << J << "]" << endl;
              cout << "The OUTPUT for index (suffix_array[i]) " << suffix_array[i] << " is " <<  J - I + 1 << endl;
              cout << "The u str_depth = " << current->str_depth_of_N << endl;
              OUTPUT[suffix_array[i]] = J - I + 1;

            }
          }
        }
      }
      else {
        // cout << "Start to find the first cut node!" << endl;
        int left = current->SA_interval[0], right = current->SA_interval[1];
        int I = suffix_array[left], J = suffix_array[left] + current->str_depth_of_N - 1;
        string target_string(reinterpret_cast<const char*>(text_string) + I, J - I + 1);

        auto start = chrono::high_resolution_clock::now();
        is_freq_survive = check_freq_periodic_survive(true, is_cut_point, r, current, left, right, I, J, freq_threshold, k, suffix_array, ippst, per_map);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        // output_stream.open("FaS_runtime", ofstream::out | ofstream::app);
        // output_stream << "Total check_FaS:" << elapsed.count() << " ";
        // output_stream.close();

        if (is_cut_point) {
          cout << "*********This is a cut node! Start binary search to find out the refined cut!********" << endl;
          is_freq_survive = false;

          // cout << "Cut node's info is I"
          for (auto const &child : children_map) {
            STvertex* child_node = child.second.v;
            int child_l = child_node->SA_interval[0], child_r = child_node->SA_interval[1];
            cout << "Current child's [l,r] is [" << child_l << "," << child_r << "]" << endl;
            for (int i = child_l; i <= child_r; i++) {
              int I = suffix_array[i], J; // left bound of the substring is fixed, we need to find out the right bound
              int low = suffix_array[i] + current->str_depth_of_N - 1, high = suffix_array[i] + child_node->str_depth_of_N - 1;
              // START BINARY SEARCH for J
              // Initialization: low is the end position of node u (cut node), high is the end position of node v (child of u)
              cout << "Binary search start! i= " << i << ", I = " << I << endl;
              J = binary_search_longest_substring(low, high, I, child_l, child_r, freq_threshold, k, is_cut_point, root, current, suffix_array, ippst, per_map);
              cout << "Binary search end! The refined cut [I, J] is [" << I << "," << J << "]" << endl;
              cout << "The OUTPUT for index (suffix_array[i]) " << suffix_array[i] << " is " <<  J - I + 1 << endl;
              // OUTPUT[suffix_array[i]] = path_map[current].second + J - I;
              OUTPUT[suffix_array[i]] = J - I + 1;
            }
          }
        }
      }
    auto total_end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = total_end - total_start;
    // output_stream.open("FaS_runtime", ofstream::out | ofstream::app);
    // output_stream << "Total while:" << elapsed.count() << "\n";
    // output_stream.close();
  }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  output_stream << elapsed.count() << "\n";
  output_stream.close();

  // map<string,int> test_map;
  
  output_stream.open(output_file);
  if(!output_stream.is_open()) {
        cout << "Couldn't open output file\n" << endl; 
       // return exit(1);
  }
  cout << "The OUTPUT with size " << text_size - 2 << " is ";
  for(int i = 1; i < text_size - 1; i++) {  // Exclude the first and last special char
    cout << OUTPUT[i] << " ";
    output_stream << OUTPUT[i] << " ";
  }
  cout << endl;
  output_stream << "\n";
  output_stream.close();


  return 0;
}