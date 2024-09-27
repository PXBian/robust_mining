/* Construction of a suffix tree using the Ukkonen algorithm
 * (with an example of searching for words in it)
 * Complexity: O(n).
 */
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <fstream>
#include <stack>
#include <algorithm>

#define FOR(I, A, B) for (INT I = (A); I <= (B); I++)
#define FORD(I, A, B) for (INT I = (A); I >= (B); I--)
#define REP(I, N) for (INT I = 0; I < (N); I++)
#define VAR(V, init) __typeof(init) V = (init)
#define FORE(I, C) for (VAR(I, (C).begin()); I != (C).end(); I++)

typedef int64_t INT;

using namespace std;

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
  	INT numer;

	// // Overload the < operator for comparison: Construct a custom set of STvertex
    // bool operator<(const STvertex& other) const {
    //     // Compare by age first, then by name if ages are the same
    //     if (numer == other.numer) {
    //         return name < other.name;
    //     }
    //     return age < other.age;
    // }
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

// vector<STvertex*> find_branch_frequent_and_build_SA(STvertex* r, int freq_threshold, unsigned char *x, int suffix_array[], int txt_size) {
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
// 				Print_edge(child.second, x);
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

void buildSuffixArray(int suffixArray[], int txt_size, STvertex *r){
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
			cout << "This is a leaf" << endl;
			cout << "The numer of this leaf is " << current_node->numer << endl;
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

    cout<<"Suffix Array for String ";
    for(int i=0; i<txt_size; i++)
        cout<<txt[i];
   	cout<<" is: ";
    for(int i=0; i<txt_size; i++)
        cout<<suffixArray[i]<<" ";
    cout<<endl;
}

vector<vector<int>> neighborInterval(vector<vector<int>> &intervals) {
    // Sort intervals based on start values
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    stack<vector<int>> mergedStack;
    mergedStack.push(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        vector<int> current = intervals[i];
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
    vector<vector<int>> mergedIntervals;
    while (!mergedStack.empty()) {
        mergedIntervals.insert(mergedIntervals.begin(), mergedStack.top());
        mergedStack.pop();
    }

    return mergedIntervals;
}


map<STvertex*,vector<int>> bottom_up_SA_interval(STvertex* r, int suffix_array[], int txt_size) {
	// int n = sizeof(suffix_array) / sizeof(suffix_array[0]);
	cout << "The sizeof suffix array is " << txt_size << endl;
	map<STvertex*,vector<int>> interval_map;

	// Stack for traversing the tree
    stack<STvertex*> traverse_stack;
    // Stack to store the post-order traversal (in reverse order)
    stack<STvertex*> result_stack;
	map<unsigned char,STedge,greater<unsigned char>> children_map;
	STvertex* current = r;
    // Start with the root node
    traverse_stack.push(current);

    // Traverse the tree using DFS & bottom-up
    while (!traverse_stack.empty()) {
        current = traverse_stack.top();
        traverse_stack.pop();
		children_map = current->g;
		bool is_root = current == r;
		cout << "Enter the DFS traverse. The current.numer is " << current->numer << ", it is root " << is_root << endl;

		if(current->numer > -1 && current->numer < txt_size) {	// current is a leaf
			// using find() to get the pointer to the occurrence of current in the SA
			int* target_ptr = find(&suffix_array[0], suffix_array + txt_size, current->numer);
			// getting index from pointer
			int current_idx = target_ptr - suffix_array;
			// Initialize the interval of the current node (leaf)
			vector<int> current_interval;
			current_interval.push_back(current_idx);
			current_interval.push_back(current_idx);
			cout << "The current_idx of this leaf is " << current_idx << endl;

			interval_map.insert(make_pair(current, current_interval));
		}
		// else {
		// Push all the children to the traversal stack (in the order they appear)
		for (auto const &child : children_map) {
			traverse_stack.push(child.second.v);
		}
		// Push the current node to the result stack: Don't push the root, as well as the special char $
		if (!is_root && current->numer < txt_size) {
			result_stack.push(current);
			cout << "Now push the " << current->numer << " into the result_stack!" << endl;
		}
        
		// }
		cout << "***********************" << endl;
		// After this bottom-up traverse finished, only the leaves has records in the interval_map
    }

	cout << "End DFS traverse, start bottom-up traverse!" << endl;
    // Now, the nodes are in reverse post-order, so we need to process them in the correct order
    while (!result_stack.empty()) {
        current = result_stack.top();
        result_stack.pop();
		cout << "Now enter the bottom-up loop, the current->numer is " << current->numer << endl;

		if(interval_map.find(current) == interval_map.end()) {	// Didn't find out the record node in interval_map
			cout << "Didn't find out the record in interval_map" << endl;
			children_map = current->g;
			vector<vector<int>> original_intervals, merged_intervals;
			for (auto const &child : children_map) {
				vector<int> child_interval = interval_map.at(child.second.v);
				original_intervals.push_back(child_interval);
			}

			merged_intervals = neighborInterval(original_intervals);
			cout << "The merged_intervals is " << endl;
			for (auto const &interval : merged_intervals) {
				cout << interval[0] << "," << interval[1] << " ";
			}
			cout << endl;
			interval_map.insert(make_pair(current, merged_intervals[0]));
		}
		else{		// Has record
			vector<int> cur_interval = interval_map.at(current);
			cout << "The current interval is " << cur_interval[0] << "," << cur_interval[1] << endl;
		}
    }

	
	return interval_map;
}


int main(int argc, char **argv)
{
	if( argc < 4 )
 	{
        cout<<"Wrong arguments!\n";
 		cout<<"./st <text_file> <pattern_file> <output_filename> <freq_threshold>\n";
 		exit(-1);
 	}
 	
	// Input text file
 	ifstream is_text;
 	is_text.open (argv[1], ios::in | ios::binary);
 	
 	ifstream in_file(argv[1], ios::binary);
   	in_file.seekg(0, ios::end);
   	INT text_file_size = in_file.tellg();

 	// Input patterns
 	string pattern_filename = argv[2];
 	
 	// Input output file
 	string output_filename = argv[3]; 

	// Input frequency threshold
 	int freq_threshold = stoi(argv[4]); 
 	
 	
	unsigned char * text_string = ( unsigned char * ) malloc (  ( text_file_size+2 ) * sizeof ( unsigned char ) );
   	char chr = 0;
  	INT text_size = 0;
  	
	for (INT i = 0; i < text_file_size - 1; i++)
	{	
		is_text.read(reinterpret_cast<char*>(&chr), 1);

		text_string[i] = chr;
		text_size++;
	}
	is_text.close();	
	text_string[ text_size ] = '$';	// Change '~' to '$' to make the symbol's ascii is smaller than the chars in txt
 	text_string[ text_size+1] = '\0';
	
	INT num_patterns = 0;
	
	unsigned char ** patterns = NULL;
	read_patterns( pattern_filename, patterns, num_patterns );
	
	ofstream pattern_output;
	pattern_output.open(output_filename);

	cout << "The text_string is " << text_string << ", text_size is " << text_size << endl;
	
	STvertex *r = Create_suffix_tree( text_string , text_size+1 );

	cout << "The number of leaves is " << liscie << endl;
	
 	vector<INT> occ;
 	INT hits = 0;
 
 	for(INT a = 0; a<num_patterns;a ++)
 	{
 		occ = Find( patterns[a], r, text_string );
 		
 		for(INT b = 0; b<occ.size(); b++ )
 		{
 			pattern_output<<patterns[a]<<" occurs at position "<<occ.at(b)<<endl;
 		}	
  		hits = hits + occ.size();
  	}
  	
  	cout<<"hits: "<<hits<<endl;

	int *suffix_array =(int*) malloc(sizeof(int) * text_size);
	buildSuffixArray(suffix_array, text_size, r);
	// vector<STvertex*> branch_freq_result = find_branch_frequent_and_build_SA(r, freq_threshold, text_string, suffix_array, text_size);
	// vector<STvertex*> branching_nodes = branch_freq_result.first, frequent_nodes = branch_freq_result.second;

	// vector<STvertex*> intersection = Intersect_branch_freq(branching_nodes, frequent_nodes);
	// cout << "---------The info of branching and frequent nodes are:---------" << endl;
	// cout << "The branching nodes are: " << endl;
	// for (auto const &n : branching_nodes) {
	// 	// for (auto const &child : n->g) {
	// 	// 	Print_edge(child.second, text_string);
	// 	// }
	// 	// cout << "**********" << endl;
	// 	// pattern_output << "The branching nodes are\n";
	// 	// pattern_output << n << "\n";
	// }
	// // cout << endl;

	// cout << "The branching frequent nodes are: " << endl;
	// for (auto const &n : branch_freq_result) {
	// 	for (auto const &child : n->g) {
	// 		Print_edge(child.second, text_string);
	// 	}
	// 	cout << "**********" << endl;
	// 	pattern_output << "The branching frequent nodes are\n";
	// 	pattern_output << n << "\n";
	// }
	// cout << endl;

	pattern_output.close();

	// Build the SA based on this ST
	// int *suffixArray =(int*) malloc(sizeof(int) * text_size);
	// buildSuffixArray(suffixArray, text_size, r);

	cout<<"Suffix Array for String ";
    for(int i=0; i<text_size; i++)
        cout<<txt[i];
   	cout<<" is: ";
    for(int i=0; i<text_size; i++)
        cout<<suffix_array[i]<<" ";
    cout<<endl;


	map<STvertex*,vector<int>> interval_map = bottom_up_SA_interval(r, suffix_array, text_size);
	cout << "---------The info of interval_map is:---------" << endl;
	for (auto const &item : interval_map) {
		cout << "The numer of this node is " << item.first->numer << endl;
		// cout << "The edges of this node is " << endl;
		// for (auto const &child : item.first->g) {
		// 	Print_edge(child.second, text_string);
		// }
		cout << "Its interval is [" << item.second[0] << "," << item.second[1] << "]" << endl;
	}


	
	STDelete(r);
	return 0;
}

