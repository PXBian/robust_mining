#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
#include <math.h> 
#include "suffixtree.hpp"

#include <iomanip> // for std::setprecision
#include <random>


using namespace std;



INT num_of_freq = 0, num_of_resi = 0;


void build_suffix_array(INT* suffixArray, INT txt_size, STvertex *r){
    for(INT i=0; i< txt_size; i++)
    { 
           suffixArray[i] = -1;
    }

	// Iterative DFS traverse to build the Suffix Array by using stack
	STvertex* current_node = r;
	STvertex* child_node;
	stack<STvertex*> traverse_stack;
	traverse_stack.push(current_node);

	INT idx = 0;
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
		else if(current_node->numer == -1) {		// current_node is a INTernal node
			for (auto const &child : children_map) {
				child_node = child.second.v;
				traverse_stack.push(child_node);
			}
		}
	}
}


vector<STvertex*> bottom_up_SA_interval(STvertex* &r, INT* &suffix_array, INT* &inv_suffix_array, unsigned char* text_string, INT txt_size, INT freq_threshold, unordered_map<string,int> &freq_map) {
	cout << "The sizeof suffix array is " << txt_size << endl;
    // karp_rabin_hashing::init();

	// Stack for traversing the tree
    stack<STvertex*> DFS_stack;
    // Stack to store the post-order traversal (in reverse order)
    stack<STvertex*> bottom_up_stack;
    STvertex* current = r;
    // vector<STvertex*> current_path;
    // vector<STvertex*> child_path;
    STvertex* child_node;
    STvertex* parent_node;
    vector<STvertex*> rev_bottomup_ordered_nodes;

    
    // map<unsigned char,STedge,greater<unsigned char>> children_map;

    // Start with the root node
    DFS_stack.push(current);
    // current_path.push_back(current);
    // current->path = current_path;
    // current->parent = new STvertex;
    // current->parent->numer = -100;
    current->str_depth_of_N = 0;
    // Traverse the tree using DFS & bottom-up
    cout << "Start DFS traverse!" << endl;

    while (!DFS_stack.empty()) {
        current = DFS_stack.top();
        DFS_stack.pop();
        // cout<<"DS size: "<<DFS_stack.size()<<endl;

        current->flag = false;
        INT current_num = current->numer;
        // vector<STvertex*> current_path = current->path;
        // current_path = current->path;
        INT current_str_depth = current->str_depth_of_N;
        // children_map = current->g;
        
        bool is_root = current == r;

        pair<INT,INT> current_interval = make_pair(-10,-10);
        if(current_num > -1 && current_num < txt_size) {	// current is a leaf
            // getting index to SA from invSA
            // cout<<"c:"<<current_num<<" ";
            INT current_idx = inv_suffix_array[current_num];
            // cout << "Current is a leaf with current_idx = " << current_idx << endl;
            // Initialize the interval of the current node (leaf)
            
            // current_interval.push_back(current_idx);
            // current_interval.push_back(current_idx);
            current_interval = {current_idx,current_idx};
        }
        current->SA_interval = current_interval;

        // Push all the children to the traversal stack (in the order they appear)
        for (auto const &child : current->g) {
            child_node = child.second.v;
            DFS_stack.push(child_node);
            INT child_edge_length = child.second.r - child.second.l + 1;
            INT child_str_depth = current_str_depth + child_edge_length;
            child_node->str_depth_of_N = child_str_depth;
            // cout << "The numer of child_node is" << child_node->numer << ", the child_edge_length is " << child_edge_length << ", the child_str_depth is " << child_str_depth << endl; 
            child_node->parent = current;
        }

        // Push the current node to the result stack: Don't push the root, as well as the special char $
        if (!is_root && current_num < txt_size) {
            // bottom_up_stack.push(current);
            rev_bottomup_ordered_nodes.push_back(current);
            // cout << "Now push the " << current->numer << " into the result_stack!" << endl;
        }
    }

    free(inv_suffix_array);
	cout << "End DFS traverse, start bottom-up ordered traverse..." << endl;

    INT tmp = 0;
    // Now, the nodes are in reverse post-order, so we need to process them in the correct order
    for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
    // while(!bottom_up_stack.empty()) {
        current = *it;
        // current = bottom_up_stack.top();
        // bottom_up_stack.pop();

        // After the DFS traverse, only leaves have SA_interval
        // if(current->SA_interval.size() == 0) {
        if (current->SA_interval.first != -10 && current->SA_interval.second != -10) {  // Skip the leaf nodes: Assume tau > 1
            // cout << "Leaf" << endl;
            continue;
        } 
        else {
            INT current_min = numeric_limits<INT>::max(), current_max = numeric_limits<INT>::min();
            for (auto const &child : current->g) {
                pair<INT,INT> child_interval = child.second.v->SA_interval;
                if (child_interval.first < current_min) {
                    current_min = child_interval.first;
                }
                if (child_interval.second > current_max) {
                    current_max = child_interval.second;
                }
            }
            current->SA_interval = {current_min,current_max};
            // cout << "[" << current_min << "," << current_max << "]" << endl;

            // Calculate the sum of the num_of_freq
            // INT range_left = current->SA_interval.first, range_right = current->SA_interval.second;
            if(current_max - current_min + 1 >= freq_threshold) {
                // tmp++;
                // cout << "This is FREQUENT" << endl;
                INT cur_str_depth = current->str_depth_of_N;
                for (INT x = 1; x <= cur_str_depth; x++) {
                    string freq_pattern = string(reinterpret_cast<char*>(text_string + suffix_array[current_min]), x);
                    // uint64_t freq_fingerprint = karp_rabin_hashing::hash_string(text_string + suffix_array[current_min],x);
                    // uint64_t freq_fingerprint = 1;
                    if (freq_map.find(freq_pattern) == freq_map.end()) {
                        unsigned char* target = const_cast<unsigned char*>(
                            reinterpret_cast<const unsigned char*>(freq_pattern.c_str()));
                        vector<INT> occ = Find(target, r, text_string );
                        freq_map.insert({freq_pattern,occ.size()});
                        // freq_map[freq_pattern] += current_max - current_min + 1;
                    }
                    
                    // cout << "freq_pattern = " << freq_pattern << ", freq_fingerprint = " << freq_fingerprint << endl;
                }
                
            }
        }
    }

    // cout << "the hashing calling times are " << tmp << endl;
    cout << "current size of freq_set = " << freq_map.size() << endl;

    return rev_bottomup_ordered_nodes;
}


vector<string> getRandomStrings(const vector<pair<string, int>>& input, size_t K) {
    vector<pair<string, int>> copy = input;

    // Seed with a real random value
    random_device rd;
    mt19937 g(rd());

    // Shuffle the copy
    shuffle(copy.begin(), copy.end(), g);

    // Adjust K if it exceeds the size
    if (K > copy.size()) K = copy.size();

    // Extract only the string parts of the first K elements
    vector<string> result;
    for (size_t i = 0; i < K; ++i) {
        result.push_back(copy[i].first);
    }

    return result;
}



int main(int argv, char** argc) {

    if(argv < 8) {
      cout << "Usage: ./reb [text_file] [freq_threshold] [number of letter substitions] [first_str_file]" << endl;
      return 1;
    }
    // Input text file
    ifstream is_text;
    string text_file = argc[1], str_file = argc[4], label_file = argc[7];

     // Input frequency threshold (tau)
    INT freq_threshold = stoi(argc[2]); 
    // Input the number of positions about letter replacements in S
    INT k = stoi(argc[3]); 
    // Input the top-K number of most frequent and resilient patterns
    INT K = stoi(argc[5]);
    // Input the number of ground truth clusters
    INT cluster_num = stoi(argc[6]);

    // Start to read the multi-str file
    // string output_file = "output/" + text_file + "_" + to_string(freq_threshold) + "_" + to_string(k);
    string text_file_path = "data/" + text_file;
    string str_file_path = "data/" + str_file;
    // string text_file_path = text_file;
    // string first_str_file = str_file;
    cout << "text_file_path is " << text_file_path << endl;
    cout << "str_file_path is " << str_file_path << endl;
    cout << "tau = " << freq_threshold << ", k = " << k << endl;
    // is_text.open (text_file_path, ios::in | ios::binary);

    
    unordered_set<string> freq_set;
    // unordered_set<string> resi_set;
    // unordered_set<string> top_resi_set;
    // karp_rabin_hashing::init();

    INT str_num = 0;
    char chr = 0;
    INT text_size = 0, max_alloc_seq_len = 0, ALLOC_SIZE = 180224;    //180224
    // unsigned char * text_string = ( unsigned char * ) malloc (  ( ALLOC_SIZE ) * sizeof ( unsigned char ) );
    max_alloc_seq_len += ALLOC_SIZE;

    double common_time = 0, inter_time = 0, final_time = 0;
 


    text_size = 0;
    max_alloc_seq_len = 0;
    unsigned char * txt_string = ( unsigned char * ) malloc (  ( ALLOC_SIZE ) * sizeof ( unsigned char ) );
    max_alloc_seq_len += ALLOC_SIZE;
    // START find the Top-K patterns in each string S and build the frequency matrix
    map<INT,unordered_map<string,INT>> frequency_matrix;
    INT string_index = 1;
    cout << "str_file_path = " << str_file_path << endl;
    is_text.open (str_file_path, ios::in | ios::binary);
    while (is_text.read(reinterpret_cast<char*>(&chr), 1)) {
		if(chr == '\n') {
            cout << "Read one line successfully!" << endl;
			txt_string[text_size] = '\1';
			txt_string[text_size+1] = '\0';


            // START find frequency for each resilient patterns
            STvertex *r = Create_suffix_tree( txt_string , text_size+1 );
            cout << "Create ST successfully! The number of leaves is " << liscie << endl;

            INT *suffix_array =(INT*) malloc(sizeof(INT) * text_size);
            build_suffix_array(suffix_array, text_size, r);
            cout << "Construct SA successfully!" << endl;

            INT *inv_suffix_array =(INT*) malloc(sizeof(INT) * text_size);
            for(INT i=0; i<text_size; i++) {
                inv_suffix_array[suffix_array[i]] = i;
            }

            unordered_map<string,INT> cur_freq_map, filter_freq_map;
            vector<STvertex*> rev_bottomup_ordered_nodes = bottom_up_SA_interval(r, suffix_array, inv_suffix_array, txt_string, text_size, freq_threshold, cur_freq_map);   // Find all frequency of frequent patterns
            cout << "Construct SA interval for each node in ST successfully. Preprocessing end!" << endl;
            // cout << "The freq_map is " << endl;
            // for(const auto &item : freq_map) {
            //     cout << "(" << item.first << "," << item.second << ")" << endl;
            // }
            // free all the arraies and ST
            // free(txt_string);
            free(suffix_array); 
            suffix_array = nullptr;
            for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
                delete *it;
            }

            for (const auto& [key, value] : cur_freq_map) {
                if (key.length() >= 3) freq_set.insert(key);  // Add the key to the set
            }

            for (const auto &item : cur_freq_map) {
                if(item.first.length() >= 3) {
                    filter_freq_map.insert(item);
                }
            }
            frequency_matrix.insert({string_index, filter_freq_map});
            string_index++;

            text_size = 0;
            max_alloc_seq_len = 0;
            txt_string = ( unsigned char * ) malloc (  ( ALLOC_SIZE ) * sizeof ( unsigned char ) );
            max_alloc_seq_len += ALLOC_SIZE;
		}
        else {
            if ( text_size >= max_alloc_seq_len ) {
				txt_string = ( unsigned char * ) realloc (txt_string, ( max_alloc_seq_len + ALLOC_SIZE ) * sizeof ( unsigned char ) );
				max_alloc_seq_len += ALLOC_SIZE;
			}

            txt_string[text_size] = chr;
            text_size++;
        }
	} 
	is_text.close();
    // Finish build frequency matrix

    // Add the excluded patterns for each string line
    for (INT i = 1; i < string_index; i++) {
        unordered_map<string,INT> cur_row_map = frequency_matrix[i];
        for (const auto &pattern : freq_set) {
            if(cur_row_map.find(pattern) == cur_row_map.end()) {
                frequency_matrix[i].insert({pattern,0});
            }
        }
    }


    cout << "frequency_matrix is " << endl;
    for (const auto &item: frequency_matrix) {
        cout << "S=" << item.first << endl;
        for (const auto &ele : item.second) {
            cout << "(" << ele.first << "," << ele.second << ") "; 
        }
        cout << endl;
    }

    // Step 1: Start normalize the original frequency matrix
    map<INT,map<string,double>> norm_frequency_matrix;
    set<string> all_features; // to gather all columns
    vector<string> top_K_features;
    for (const auto& [row, features] : frequency_matrix) {
        int row_sum = 0;
        for (const auto& [feature, count] : features) {
            row_sum += count;
            all_features.insert(feature);
        }

        for (const auto& [feature, count] : features) {
            norm_frequency_matrix[row][feature] = (row_sum > 0) ? static_cast<double>(count) / row_sum : 0.0;
        }
    }

    cout << "\nNormalized matrix with all features:\n";
    for (const auto& [row, features] : norm_frequency_matrix) {
        cout << "Row " << row << ": ";
        for (const auto& [feature, value] : features) {
            cout << feature << "=" << value << " ";
        }
        cout << '\n';
    }


    // // Step 2: Sum each column across rows
    map<string, double> column_sums;
    for (const auto& [row, features] : norm_frequency_matrix) {
        for (const auto& [feature, value] : features) {
            column_sums[feature] += value;
        }
    }

    // Step 3: Get top-K features with largest column sums
    
    vector<pair<string, double>> sorted_columns(column_sums.begin(), column_sums.end());
    sort(sorted_columns.begin(), sorted_columns.end(), 
        [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second; // descending
        // return a.second < b.second; // increasing
    });

    set<string> top_k_features;
    vector<string> top_k_features_vec;
    for (int i = 0; i < min(K, (int)sorted_columns.size()); ++i) {
        top_k_features.insert(sorted_columns[i].first);
        top_k_features_vec.push_back(sorted_columns[i].first);
    }

    // Step 4: Create a reduced normalized matrix (only top-K features) and re-normalize each row
    map<INT, map<string, double>> reduced_norm_matrix;
    for (const auto& [row, features] : norm_frequency_matrix) {
        double new_row_sum = 0.0;

        // First pass: compute sum of only top-K features
        for (const auto& [feature, value] : features) {
            if (top_k_features.count(feature)) {
                new_row_sum += value;
            }
        }

        // Second pass: re-normalize only top-K features
        for (const auto& [feature, value] : features) {
            if (top_k_features.count(feature)) {
                reduced_norm_matrix[row][feature] = (new_row_sum > 0.0) ? value / new_row_sum : 0.0;
            }
        }
    }

    // // Output result
    // cout << "\nTop-K features: ";
    // for (const auto& f : top_k_features_vec) {
    //     cout << f << " ";
    // }
    // cout << "\nRe-normalized matrix with top-K features:\n";
    // for (const auto& [row, features] : reduced_norm_matrix) {
    //     cout << "Row " << row << ": ";
    //     for (const auto& [feature, value] : features) {
    //         cout << feature << "=" << value << " ";
    //     }
    //     cout << '\n';
    // }

    // Write to CSV
    ofstream nor_file("normalized_freq_matrix.csv");
    if (nor_file.is_open()) {
        // Write header
        nor_file << "Sample";
        for (const auto& feature : top_k_features_vec) {
            nor_file << "," << feature;
        }
        nor_file << "\n";

        // Write data rows
        for (const auto& [row, features] : reduced_norm_matrix) {
            nor_file << row;
            for (const auto& feature : top_k_features_vec) {
                double val = features.count(feature) ? features.at(feature) : 0.0;
                nor_file << "," << val;
            }
            nor_file << "\n";
        }
    }
    nor_file.close();

    string command_str = "python3 cluster.py normalized_freq_matrix.csv data/" + label_file + " 42 " + to_string(freq_threshold) + " " + to_string(k) + " " + to_string(K) + " rebuttal_results_freq_local.csv";
    cout << "////// Execute clustering algorithm: " << command_str << " //////" << endl;
    const char* command = command_str.c_str();
    system(command);


    cout << "Finish Reb program!\n" << endl;

  return 0;
}