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


vector<STvertex*> bottom_up_SA_interval(STvertex* &r, INT* &suffix_array, INT* &inv_suffix_array, unsigned char* text_string, INT txt_size, INT freq_threshold, unordered_set<uint64_t> &freq_set) {
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
                    // string freq_pattern = string(reinterpret_cast<char*>(text_string + suffix_array[current_min]), x);
                    uint64_t freq_fingerprint = karp_rabin_hashing::hash_string(text_string + suffix_array[current_min],x);
                    // uint64_t freq_fingerprint = 1;
                    freq_set.insert(freq_fingerprint);
                    // cout << "freq_pattern = " << freq_pattern << ", freq_fingerprint = " << freq_fingerprint << endl;
                }
                
            }
        }
    }

    // cout << "the hashing calling times are " << tmp << endl;
    cout << "current size of freq_set = " << freq_set.size() << endl;

    return rev_bottomup_ordered_nodes;
}

bool isFileSizeNormal(const string& filePath) {
    ifstream file(filePath, ios::binary | ios::ate); // Open file in binary mode at the end
    if (!file) {
        cerr << "Error: Could not open file: " << filePath << endl;
        return false;
    }

    streamsize fileSize = file.tellg(); // Get the size of the file
    file.close();

    const streamsize low_limit = 5 * 1024; // 5 KB in bytes
    const streamsize up_limit = 108 * 1024; // 5 KB in bytes

    if(fileSize > up_limit || fileSize < low_limit) {
        return false;
    }

    return true;
}

int main(int argv, char** argc) {

    if(argv < 4) {
      cout << "Usage: ./main [dataset_prefix] [freq_threshold] [number of letter substitions]" << endl;
      return 1;
    }
    // Input text file
    ifstream is_text;
    ofstream output_stream;
    string dataset_prefix = argc[1];

     // Input frequency threshold (tau)
    INT freq_threshold = stoi(argc[2]); 
    // Input the number of positions about letter replacements in S
    INT k = stoi(argc[3]); 
    // Input the version we want to check
    INT version = stoi(argc[4]);   // wiki
    // // Input the number of losing patterns between different versions
    // INT M = stoi(argc[5]);


    // Start to read the multi-str file
    // string output_file = "output/" + text_file + "_" + to_string(freq_threshold) + "_" + to_string(k);
    // string text_file_path = "data/" + text_file;
    // string first_str_file = "data/" + str_file;
    // string text_file_path = text_file;
    // // string first_str_file = str_file;
    // cout << "text_file_path is " << text_file_path << endl;
    cout << "dataset_prefix is " << dataset_prefix << endl;
    cout << "tau = " << freq_threshold << ", k = " << k << ", version = " << version <<  endl;

    
    unordered_set<uint64_t> first_freq_set;
    // unordered_set<uint64_t> common_freq_set;
    // unordered_set<uint64_t> resi_set;
    unordered_set<uint64_t> first_resi_set;
    karp_rabin_hashing::init();

     // Run the first str in MAIN algorithm
    string command_str = "./esa " + dataset_prefix + "_1.txt " + to_string(freq_threshold) + " " + to_string(k);
    cout << "////// Execute MAIN algorithm: " << command_str << " //////" << endl;
    const char* command = command_str.c_str();
    system(command);
    cout << "////// Finish executing MAIN algorithm to find 1st version's resilient //////" << endl; 

    command_str = "rm freq_resi_record.csv";
    command = command_str.c_str();
    system(command);

    INT target_freq_ver = INT_MAX, target_resi_ver = INT_MAX;
    INT init_freq_size = 0, init_resi_size = 0;

    // set<INT> ver_set = {1,version};
    // for(const auto &ver : ver_set) {

    for (INT ver = 1; ver <= version; ver++) {
    //     if (ver == 2699) {
    //         continue;
    //     }

        unordered_set<uint64_t> freq_set;
        string ver_file = dataset_prefix + "_" + to_string(ver) + ".txt";
        cout << "ver_file = " << ver_file << endl;

        // Only for wiki dataset
        if (ver == 2699 || ver == 5375) {
            continue;
        }
        if (isFileSizeNormal(ver_file) == false) {
            continue;
        }


       
        // Read first version file
        is_text.open (ver_file, ios::in | ios::binary);
        ifstream in_file(ver_file, ios::binary);
        in_file.seekg(0, ios::end);
        // INT text_file_size = in_file.tellg();
        INT text_file_size = in_file.tellg();

        unsigned char * text_string = ( unsigned char * ) malloc (  ( text_file_size+2 ) * sizeof ( unsigned char ) );
        char chr = 0;
        // INT text_size = 0;
        INT text_size = 0;
        for (INT i = 0; i < text_file_size - 1; i++) {	
            is_text.read(reinterpret_cast<char*>(&chr), 1);
            text_string[i] = chr;
            // cout << "i=" << i << "," << chr << "(" << text_size << "),dec_value=" << (unsigned INT)chr << "; ";
            text_size++;
        }
        is_text.close();
        // cout << endl;
        
        text_string[ text_size] = 255;
        text_string[ text_size+1] = '\0';	// Change '~' to '!' to make the symbol's ascii is smaller than the chars in txt
        text_size = text_size + 1;  // Do not include the final \0
        cout << "Finish reading the text file! text_size = " << text_size << endl;

        // unordered_set<uint64_t> resi_set;
        // Read the OUTPUT file and get the resilient substrings. Store them in resi_set (Y)
        cout << "Start to read the MAIN OUTPUT!" << endl;
        ifstream file("main_output");
        string line;
        INT index = 0;
        if(ver == 1) {
            if (file.is_open()) {
                while (getline(file, line)) {
                    int current_len = stoi(line);
                    // cout << "current_len = " << current_len << ", index = " << index << endl;
                    // string str(reinterpret_cast<char*>(txt_string + index), current_len);
                    for(INT i = 1; i <= current_len; i++) {
                        uint64_t str = karp_rabin_hashing::hash_string(text_string + index, i);
                        first_resi_set.insert(str);
                    }
                    
                    index ++;
                }
                file.close();
            }
            // Finish finding the current version's resilient patterns' set
        
            // first_resi_set = resi_set;
            // cout << "********The size of first_resi_set = " << first_resi_set.size() << "*******" << endl;
            // cout << "The first_resi_set is " << endl;
            // for(const auto &item : first_resi_set) {
            //     cout << item << " ";
            // }
            // cout << endl;
            // resi_set.clear();
        }


        // Start finding the current version's frequent patterns' set
        STvertex *r = Create_suffix_tree( text_string , text_size+1 );
        cout << "Create ST successfully! The number of leaves is " << liscie << endl;

        INT *suffix_array =(INT*) malloc(sizeof(INT) * text_size);
        build_suffix_array(suffix_array, text_size, r);
        cout << "Construct SA successfully!" << endl;

        INT *inv_suffix_array =(INT*) malloc(sizeof(INT) * text_size);
        for(INT i=0; i<text_size; i++) {
            inv_suffix_array[suffix_array[i]] = i;
        }

        vector<STvertex*> rev_bottomup_ordered_nodes = bottom_up_SA_interval(r, suffix_array, inv_suffix_array, text_string, text_size, freq_threshold, freq_set);
        cout << "Construct SA interval for each node in ST successfully. Preprocessing end!" << endl;
        

        if(ver == 1) {
            // cout << "********The size of freq_set = " << freq_set.size() << "*******" << endl;
            int freq_count = 0;
            // for(const auto item : freq_set) {
            //     first_freq_set.insert(item);
            //     freq_count++;
            // }
            first_freq_set = freq_set;
            // cout << "After building the common_freq_set, str_num = " << str_num << endl;
            cout << "********The initial size of first_freq_set = " << first_freq_set.size() << endl;
            cout << "********The initial size of first_resi_set = " << first_resi_set.size() << endl;

            init_freq_size = first_freq_set.size();
            init_resi_size = first_resi_set.size();
            // cout << "The first_freq_set is " << endl;
            // for(const auto &item : first_freq_set) {
            //     cout << item << " ";
            // }
            // cout << endl;

            freq_set.clear();

            output_stream.open("freq_resi_record.csv", ios::app);
            if(!output_stream.is_open()) {
                    cout << "Couldn't open output file\n" << endl; 
            }

            output_stream << ver << "," << first_freq_set.size() << "," << first_resi_set.size() << "\n";

            output_stream.close();
            continue;
        }
        
        unordered_set<uint64_t> resi_intersection_set;
        unordered_set<uint64_t> freq_intersection_set;
        for(const auto &item : first_freq_set) {
            if(freq_set.find(item) != freq_set.end()) {
                freq_intersection_set.insert(item);
            }
        }
        first_freq_set.clear();
        for (const auto &item : freq_intersection_set) {
            first_freq_set.insert(item);
        }

        for(const auto &item : first_resi_set) {
            // if(resi_set.find(item) != resi_set.end()) {
            if(freq_set.find(item) != freq_set.end()) {
                resi_intersection_set.insert(item);
            }
        }
        first_resi_set.clear();
        for (const auto &item : resi_intersection_set) {
            first_resi_set.insert(item);
        }
        freq_set.clear();

        // free all the arraies and ST
        free(text_string);
        free(suffix_array);

        // text_string = nullptr;
        // suffix_array = nullptr;
        // inv_suffix_array = nullptr;

        for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
            delete *it;
        }
        // cout << "Clear all the data structure succesffully! ver = " << ver << endl;

        // cout << "Initial first_freq_set size is " << init_freq_size << ", current first_freq_set size is " << first_freq_set.size() << endl;
        // cout << "Initial first_resi_set size is " << init_resi_size << ", current first_resi_set size is " << first_resi_set.size() << endl;
        // if ((init_freq_size - first_freq_set.size()) >= M && ver < target_freq_ver) {
        //     target_freq_ver = ver;
        //     cout << "RECORD target_freq_ver = " << target_freq_ver << endl;
        // }
        // if ((init_resi_size - first_resi_set.size()) >= M && ver < target_resi_ver) {
        //     target_resi_ver = ver;
        //     cout << "RECORD target_resi_ver = " << target_resi_ver << endl;
        // }
        
        output_stream.open("freq_resi_record.csv", ios::app);
        if(!output_stream.is_open()) {
                cout << "Couldn't open output file\n" << endl; 
        }

        output_stream << ver << "," << first_freq_set.size() << "," << first_resi_set.size() << "\n";
        output_stream.close();

    }

    output_stream.open("M_result.csv", ios::app);
    if(!output_stream.is_open()) {
            cout << "Couldn't open output file\n" << endl; 
    }
    INT M_freq = init_freq_size - first_freq_set.size();
    INT M_resi = init_resi_size - first_resi_set.size();

    output_stream << to_string(freq_threshold) << "," << to_string(k) << "," << to_string(version) << "," << to_string(M_freq) << "," << to_string(M_resi) << "\n";
    output_stream.close();

    


    // auto start = chrono::high_resolution_clock::now();
    // Get the intersection of X and Y
    // ofstream out_file ("inter_1");
    
    // out_file.close();
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double> elapsed = end - start;
    // final_time = elapsed.count();

    // unordered_set<uint64_t> resi_union_set = common_freq_set;
    // unordered_set<uint64_t> freq_union_set = common_freq_set;

    // resi_union_set.insert(resi_set.begin(), resi_set.end());
    // freq_union_set.insert(first_freq_set.begin(), first_freq_set.end());


    // INT common_freq_size = common_freq_set.size();
    // INT resi_inter_size = resi_intersection_set.size();
    // INT resi_union_size = resi_union_set.size();
    // INT freq_inter_size = freq_intersection_set.size();
    // INT freq_union_size = freq_union_set.size();
    // cout << "common_freq_size (Y) = " << common_freq_size << endl;
    // cout << "resi_inter_size = " << resi_inter_size << ", resi_union_size = " << resi_union_size << ", resi_inter_ratio = " << double(resi_inter_size) / double(common_freq_size) << ", resi_jac_ratio = " << double(resi_inter_size) / double(resi_union_size) << endl;
    // cout << "freq_inter_size = " << freq_inter_size << ", freq_union_size = " << freq_union_size << ", freq_inter_ratio = " << double(freq_inter_size) / double(common_freq_size) << ", freq_jac_ratio = " << double(freq_inter_size) / double(freq_union_size) << endl;

    // cout << "common_time = " << common_time << ", inter_time = " << inter_time << ", first_part_total = " << common_time + inter_time << endl;

    

    cout << "Finish Case Study!\n" << endl;

  return 0;
}