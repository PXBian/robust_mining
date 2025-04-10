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
#include "utils.hpp"
#include "karp_rabin_hashing.hpp"
#include <iomanip> // for std::setprecision


using namespace std;


namespace karp_rabin_hashing {

//=============================================================================
// Base and exponent used in Karp-Rabin hashing.
//=============================================================================
std::uint64_t hash_variable;
std::uint64_t mersenne_prime_exponent;

//=============================================================================
// Return (a * b) mod p, where p = (2^k) - 1.
// Requires a, b <= 2^k. Tested for k = 1, .., 63.
//=============================================================================
std::uint64_t mul_mod_mersenne(
    const std::uint64_t a,
    const std::uint64_t b,
    const std::uint64_t k) {
  const std::uint64_t p = ((std::uint64_t)1 << k) - 1;
  __extension__ const unsigned __int128 ab =
    (unsigned __int128)a *
    (unsigned __int128)b;
  std::uint64_t lo = (std::uint64_t)ab;
  const std::uint64_t hi = (ab >>  (uint64_t) 64);
  lo = (lo & p) + ((lo >> k) + (hi << ( (uint64_t) 64 - k)));
  lo = (lo & p) + (lo >> k);
  return lo == p ?  (uint64_t) 0 : lo;
}

//=============================================================================
// Return a mod p, where p = (2^k) - 1.
// Works for any a in [0..2^64).
// Tested for k = 1, .., 63.
//=============================================================================
std::uint64_t mod_mersenne(
    std::uint64_t a,
    const std::uint64_t k) {
  std::uint64_t p = ((std::uint64_t)1 << k) -  (uint64_t) 1;
  if (k < (uint64_t) 32) {

    // We need to check if a <= 2^(2k).
    const std::uint64_t threshold = ((std::uint64_t)1 << (k <<  (uint64_t) 1));
    if (a <= threshold) {
      a = (a & p) + (a >> k);
      a = (a & p) + (a >> k);
      return a == p ?  (uint64_t) 0 : a;
    } else return a % p;
  } else {

    // We are guaranteed that a < 2^(2k)
    // because a < 2^64 <= 2^(2k).
    a = (a & p) + (a >> k);
    a = (a & p) + (a >> k);
    return a == p ?  (uint64_t) 0 : a;
  }
}

//=============================================================================
// Return random number x in [0..p), where p = (2^k) - 1.
//=============================================================================
std::uint64_t rand_mod_mersenne(const std::uint64_t k) {
  const std::uint64_t p = ((std::uint64_t)1 << k) -  (uint64_t) 1;
  return utils::random_int<std::uint64_t>(
      (std::uint64_t)0, (std::uint64_t(p -  (uint64_t) 1)));
}

//=============================================================================
// Return (a^n) mod p, where p = (2^k) - 1.
//=============================================================================
std::uint64_t  pow_mod_mersenne(
    const std::uint64_t a,
    std::uint64_t n,
    const std::uint64_t k) {
  std::uint64_t pow = mod_mersenne(a, k);
  std::uint64_t ret = mod_mersenne( (uint64_t) 1, k);
  while (n >  (uint64_t) 0) {
    if (n &  (uint64_t) 1)
      ret = mul_mod_mersenne(ret, pow, k);
    pow = mul_mod_mersenne(pow, pow, k);
    n >>=  (uint64_t) 1;
  }
  return ret;
}

//=============================================================================
// Given Karp-Rabin hashes of two substrings, return
// the Karp-Rabin hash of their concatenation.
//=============================================================================
std::uint64_t concat(
    const std::uint64_t left_hash,
    const std::uint64_t right_hash,
    const std::uint64_t right_len) {
  const std::uint64_t pow = pow_mod_mersenne(
      hash_variable, right_len, mersenne_prime_exponent);
  const std::uint64_t tmp = mul_mod_mersenne(
      left_hash, pow, mersenne_prime_exponent);
  const std::uint64_t ret = mod_mersenne(
      tmp + right_hash, mersenne_prime_exponent);
  return ret;
}
std::uint64_t power(const std::uint64_t k)
{
	return pow((uint64_t)2,k);
}

std::uint64_t subtract(
        const std::uint64_t long_hash,
        const std::uint64_t short_hash,
        const std::uint64_t right_len) {
    const std::uint64_t pow = pow_mod_mersenne(
            hash_variable, right_len, mersenne_prime_exponent);
    const std::uint64_t tmp = mul_mod_mersenne(
            short_hash, pow, mersenne_prime_exponent);
    const std::uint64_t p = ((std::uint64_t)1 << mersenne_prime_exponent) - 1;
    return (long_hash >= tmp) ?
           (long_hash - tmp) :
           ((long_hash + p) - tmp);
}

//=============================================================================
// Initialize the base and exponent for Karp-Rabin hashing.
//=============================================================================
void init() {
  mersenne_prime_exponent = 61;
  hash_variable = rand_mod_mersenne(mersenne_prime_exponent);
}

}  // namespace karp_rabin_kashing

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

// Check if a 4-mer contains only A, T, C, G
bool isValidKmer(const unsigned char* kmer, int k) {
    for (int i = 0; i < k; ++i) {
        char c = kmer[i];
        if (c != 'A' && c != 'T' && c != 'C' && c != 'G') return false;
    }
    return true;
}

vector<string> extractValidKmers(const unsigned char* txt_string, size_t length, int k) {
    vector<string> kmers;
    for (size_t i = 0; i <= length - k; ++i) {
        if (isValidKmer(txt_string + i, k)) {
            kmers.emplace_back(reinterpret_cast<const char*>(txt_string + i), k);
        }
    }
    return kmers;
}


int main(int argv, char** argc) {

    if(argv < 7) {
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

    unordered_map<string,int> freq_map;
    unordered_set<string> resi_set;
    unordered_set<string> top_resi_set;
    karp_rabin_hashing::init();

    INT str_num = 0;
    char chr = 0;
    INT text_size = 0, max_alloc_seq_len = 0, ALLOC_SIZE = 180224;    //180224
    // unsigned char * text_string = ( unsigned char * ) malloc (  ( ALLOC_SIZE ) * sizeof ( unsigned char ) );
    max_alloc_seq_len += ALLOC_SIZE;

    double common_time = 0, inter_time = 0, final_time = 0;
    

    // // Run the first str in MAIN algorithm
    // string command_str = "./main " + text_file_path + " " + to_string(freq_threshold) + " " + to_string(k);
    // cout << "////// Execute MAIN algorithm: " << command_str << " //////" << endl;
    // const char* command = command_str.c_str();
    // system(command);
    // cout << "////// Finish executing MAIN algorithm to find resilient //////" << endl; 
    

    // Read the concentate string to set text_string
    text_size = 0;
    max_alloc_seq_len = 0;
    unsigned char * txt_string = ( unsigned char * ) malloc (  ( ALLOC_SIZE ) * sizeof ( unsigned char ) );
    max_alloc_seq_len += ALLOC_SIZE;
    is_text.open (text_file_path, ios::in | ios::binary);
    while (is_text.read(reinterpret_cast<char*>(&chr), 1)) {
		if(chr == '\n') {
            cout << "Read the whole line successfully!" << endl;
			txt_string[text_size] = '\1';
			txt_string[text_size+1] = '\0';

            // string str(reinterpret_cast<char*>(txt_string), text_size+1);
            // cout << "current str is " << str << endl;

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

            vector<STvertex*> rev_bottomup_ordered_nodes = bottom_up_SA_interval(r, suffix_array, inv_suffix_array, txt_string, text_size, freq_threshold, freq_map);   // Find all frequency of frequent patterns
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

            text_size = 0;
            max_alloc_seq_len = 0;
            // txt_string = ( unsigned char * ) malloc (  ( ALLOC_SIZE ) * sizeof ( unsigned char ) );
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
    // cout << "Finish the whole line here" << endl;

    // // READ the output of all global resilient patterns 
    // string line;
    // INT index = 0;
    // ifstream file("main_output");
    // if (file.is_open()) {
    //     while (getline(file, line)) {
    //         int current_len = stoi(line);
    //         // cout << "current_len = " << current_len << ", index = " << index << endl;
    //         // string str(reinterpret_cast<char*>(txt_string + index), current_len);
    //         for(INT i = 1; i <= current_len; i++) {
    //             // uint64_t str = karp_rabin_hashing::hash_string(txt_string + index, i);
    //             string str(reinterpret_cast<char*>(txt_string + index), i);
    //             resi_set.insert(str);
    //         }
            
    //         index ++;
    //     }
    //     file.close();
    // }
    // // FINISH reading the resilient patterns from the concatenation

    

    // cout << "The global resilient patterns are: " << endl;
    // for(const auto &item : resi_set) {
    //     cout << item << " ";
    // }
    // cout << endl;

    // GET TOP-K most frequent resilient patterns
    // Step 1: Copy to a vector
    // vector<pair<string, int>> freq_vec(freq_map.begin(), freq_map.end());

    // // Step 2: Sort by value in descending order
    // sort(freq_vec.begin(), freq_vec.end(), 
    //     [](const pair<string, int>& a, const pair<string, int>& b) {
    //     return a.second > b.second; // descending
    // });

    // vector<string> top_K_freq_vec;
    // int top_count = 0;
    // cout << "The freq_vec is " << endl;
    // for (auto const &item : freq_vec) {
    //     // cout << "(" << item.first << "," << item.second << ") ";
    //     // if(resi_set.find(item.first) != resi_set.end() && top_count < K) {
    //     //     top_K_freq_resi_vec.push_back(item.first);
    //     //     top_count++;
    //     // }
    //     top_K_freq_vec.push_back(item.first);
    //     top_count++;
    //     if(top_count >= K) {
    //         break;
    //     }
    // }
    // cout << endl;
    // cout << "The global Top-K frequent patterns are: " << endl;
    // for(const auto &item : top_K_freq_vec) {
    //     cout << item << " ";
    // }
    // cout << endl;
    // FINISH finding the (global) Top-K frequent resilient patterns

    int k_mer = 4;
    size_t len = strlen(reinterpret_cast<const char*>(txt_string));
    vector<string> kmers_patterns = extractValidKmers(txt_string, len, k_mer);


    free(txt_string);
    txt_string = nullptr;

    text_size = 0;
    max_alloc_seq_len = 0;
    txt_string = ( unsigned char * ) malloc (  ( ALLOC_SIZE ) * sizeof ( unsigned char ) );
    max_alloc_seq_len += ALLOC_SIZE;
    // START find the Top-K patterns in each string S and build the frequency matrix
    map<INT,map<string,INT>> frequency_matrix;
    INT string_index = 1;
    cout << "str_file_path = " << str_file_path << endl;
    is_text.open (str_file_path, ios::in | ios::binary);
    while (is_text.read(reinterpret_cast<char*>(&chr), 1)) {
		if(chr == '\n') {
            cout << "Read one line successfully!" << endl;
			txt_string[text_size] = '\1';
			txt_string[text_size+1] = '\0';

            // string str(reinterpret_cast<char*>(txt_string), text_size+1);
            // cout << "current str is " << str << endl;

            // START find frequency for each resilient patterns
            STvertex *r = Create_suffix_tree( txt_string , text_size+1 );
            cout << "Create ST successfully! The number of leaves is " << liscie << endl;

            map<string,INT> cur_row_map;
            vector<INT> occ;
            for(auto const &pattern : kmers_patterns) {
                unsigned char* target = const_cast<unsigned char*>(
                    reinterpret_cast<const unsigned char*>(pattern.c_str()));
                occ = Find(target, r, txt_string );
                cur_row_map.insert({pattern,occ.size()});
            }
            frequency_matrix.insert({string_index, cur_row_map});
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

    cout << "frequency_matrix is " << endl;
    for (const auto &item: frequency_matrix) {
        cout << "S=" << item.first << endl;
        for (const auto &ele : item.second) {
            cout << "(" << ele.first << "," << ele.second << ") "; 
        }
        cout << endl;
    }

    // Start normalize the frequency matrix
    map<INT,map<string,double>> norm_frequency_matrix;
    set<string> all_features; // to gather all columns
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

    // Write to CSV
    ofstream nor_file("normalized_kmer_matrix.csv");
    if (nor_file.is_open()) {
        // Write header
        nor_file << "Sample";
        for (const auto& feature : all_features) {
            nor_file << "," << feature;
        }
        nor_file << "\n";

        // Write data rows
        for (const auto& [row, features] : norm_frequency_matrix) {
            nor_file << row;
            for (const auto& feature : all_features) {
                double val = features.count(feature) ? features.at(feature) : 0.0;
                nor_file << "," << val;
            }
            nor_file << "\n";
        }
    }

    nor_file.close();

    string command_str = "python3 cluster.py normalized_kmer_matrix.csv data/" + label_file + " 42 " + to_string(freq_threshold) + " " + to_string(k) + " " + to_string(K) + " rebuttal_results_kmer.csv";
    cout << "////// Execute clustering algorithm: " << command_str << " //////" << endl;
    const char* command = command_str.c_str();
    system(command);


    cout << "Finish Reb program!\n" << endl;

  return 0;
}