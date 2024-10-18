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
#include "suffixtree.hpp"

using namespace std;
using namespace Intervals;

// using namespace PrioritySearchTree;

// int is_periodic_yes = 0, is_periodic_no = 0;
int num_of_freq = 0, num_of_resi = 0;


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


vector<STvertex*> bottom_up_SA_interval(STvertex* &r, int* &suffix_array, int* &inv_suffix_array, int txt_size, int freq_threshold) {
	cout << "The sizeof suffix array is " << txt_size << endl;

	// Stack for traversing the tree
  stack<STvertex*> DFS_stack;
  // Stack to store the post-order traversal (in reverse order)
  stack<STvertex*> bottom_up_stack;
	STvertex* current = r;
  vector<STvertex*> current_path;
  vector<STvertex*> child_path;
  STvertex* child_node;
  STvertex* parent_node;
  vector<STvertex*> rev_bottomup_ordered_nodes;
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
    }

    // Push the current node to the result stack: Don't push the root, as well as the special char $
    if (!is_root && current_num < txt_size) {
      // bottom_up_stack.push(current);
      rev_bottomup_ordered_nodes.push_back(current);
      // cout << "Now push the " << current->numer << " into the result_stack!" << endl;
    }

  }

	cout << "End DFS traverse, start bottom-up ordered traverse..." << endl;

  // Now, the nodes are in reverse post-order, so we need to process them in the correct order
  for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
    current = *it;

    // After the DFS traverse, only leaves have SA_interval
    if(current->SA_interval.size() == 0) {
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

    // Calculate the sum of the num_of_freq
    int range_left = current->SA_interval[0], range_right = current->SA_interval[1];
    if(range_right - range_left + 1 >= freq_threshold) {
        current_path = current->path;
        parent_node = current_path[current_path.size() - 2];
        int parent_str_depth = parent_node->str_depth_of_N, cur_str_depth = current->str_depth_of_N;
        num_of_freq = num_of_freq + (cur_str_depth - parent_str_depth);
        // cout << "Now add " << cur_str_depth - parent_str_depth << " to num_of_freq, num_of_freq = " << num_of_freq << endl;
    }
  }

  return rev_bottomup_ordered_nodes;
}

int main(int argv, char** argc) {

   if(argv < 4) {
      cout << "Usage: ./main [text_file] [freq_threshold] [number of letter substitions]" << endl;
      return 1;
    }
    // Input text file
    ifstream is_text;
    string text_file = argc[1];

     // Input frequency threshold (tau)
    int freq_threshold = stoi(argc[2]); 
    // Input the number of positions about letter replacements in S
    int k = stoi(argc[3]); 

    string output_file = "output/" + text_file + "_" + to_string(freq_threshold) + "_" + to_string(k);

    string text_file_path = "data/" + text_file;
    is_text.open (text_file_path, ios::in | ios::binary);
    
    ifstream in_file(text_file_path, ios::binary);
    in_file.seekg(0, ios::end);
    // INT text_file_size = in_file.tellg();
    int32_t text_file_size = in_file.tellg();

    
    unsigned char * text_string = ( unsigned char * ) malloc (  ( text_file_size+4 ) * sizeof ( unsigned char ) );
    char chr = 0;
    // INT text_size = 0;
    int32_t text_size = 0;
    
    string runtime_detail_csv = "runtime_details.csv";
    ofstream output_stream;
    output_stream.open(runtime_detail_csv, ios::app);
    output_stream << "text_file,tau,k,read_txt,create_ST,create_SA,create_intervals,is_periodic_preprocess,find_cut,total\n";
    // output_stream << "text_file,tau,k,total_runtime\n";
    output_stream << text_file << "," << to_string(freq_threshold) << "," << to_string(k) << ",";
    output_stream.close();

    // At the beginning and end of S, add two $ to ensure the all_run runs successfully!
    auto start = chrono::high_resolution_clock::now();
    text_string[0] = '\1';
    // cout << "text_file_size is " << text_file_size << ", start reading! " << endl;
    // for (INT i = 1; i <= text_file_size; i++) {	
    for (int32_t i = 1; i <= text_file_size; i++) {	
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
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double> elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();

    // auto whole_start = chrono::high_resolution_clock::now();
    
    // Pre-processing begin
    // start = chrono::high_resolution_clock::now();
    STvertex *r = Create_suffix_tree( text_string , text_size+1 );
    cout << "Create ST successfully! The number of leaves is " << liscie << endl;
    // end = chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();

    // start = chrono::high_resolution_clock::now();
    int *suffix_array =(int*) malloc(sizeof(int) * text_size);
    build_suffix_array(suffix_array, text_size, r);
    cout << "Construct SA successfully!" << endl;
    // end = chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();
    
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
    // start = chrono::high_resolution_clock::now();
    vector<STvertex*> rev_bottomup_ordered_nodes = bottom_up_SA_interval(root, suffix_array, inv_suffix_array, text_size, freq_threshold);
    cout << "Construct SA interval for each node in ST successfully. Preprocessing end!" << endl;
    // end = chrono::high_resolution_clock::now();
    // elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();
    free(inv_suffix_array);
    // Pre-processing end

    // Clear suffix array, suffix tree and interval tree
    free(suffix_array);
    STDelete(r);
    //   runs.clear();

  
  // output_stream.open(output_file);
//   output_stream.open("main_output");
//   if(!output_stream.is_open()) {
//         cout << "Couldn't open output file\n" << endl; 
//   }
//   // cout << "The OUTPUT with size " << text_size - 2 << " is ";
//   for(int i = 1; i < text_size - 2; i++) {  // Exclude the first and last special char
//     // cout << OUTPUT[i] << " ";
//     output_stream << OUTPUT[i] << "\n";
//   }
//   // cout << endl;
//   output_stream.close();
//   free(OUTPUT);

//   if(freq_threshold == 2) num_of_freq--;    // Remove the case of two \1 at the beginning and end of string S
//   cout << "The num_of_freq = " << num_of_freq << ", num_of_resi = " << num_of_resi << ", num_of_resi / num_of_freq = " << (double) num_of_resi / (double) num_of_freq << ", num_of_freq - num_of_resi = " << num_of_freq - num_of_resi << endl;

  cout << "Finish!\n" << endl;

  // cout << "\nThe count of is_periodic_yes = " << is_periodic_yes << ", count of is_periodic_no = " << is_periodic_no << endl;


  return 0;
}