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

// INT is_periodic_yes = 0, is_periodic_no = 0;
INT num_of_freq = 0, num_of_resi = 0;
INT freq_count = 0, resi_count = 0;
vector<INT> outlier;

void build_suffix_array(INT* suffixArray, INT txt_size, STvertex *r){
    for(INT i=0; i< txt_size; i++)
        suffixArray[i] = -1;
    
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


vector<STvertex*> bottom_up_SA_interval(STvertex* r, INT* &suffix_array, INT* &inv_suffix_array, INT txt_size, INT freq_threshold) {
	cout << "The sizeof suffix array is " << txt_size << endl;

	// Stack for traversing the tree
  stack<STvertex*> DFS_stack;
  // Stack to store the post-order traversal (in reverse order)
  stack<STvertex*> bottom_up_stack;
	STvertex* current = r;
  STvertex* child_node;
  STvertex* parent_node;
  vector<STvertex*> rev_bottomup_ordered_nodes;
  // map<unsigned char,STedge,greater<unsigned char>> children_map;


  // Traverse the tree using DFS & bottom-up
  cout << "Start DFS traverse!" << endl;

  // Start with the root node
  DFS_stack.push(current);
  current->str_depth_of_N = 0;

  while (!DFS_stack.empty()) {
    current = DFS_stack.top();
    DFS_stack.pop();
    current->flag = false;
    INT current_num = current->numer;
    INT current_str_depth = current->str_depth_of_N;
	  // children_map = current->g;
    
	  bool is_root = current == r;
    // cout << "is_root = " << is_root << endl;

	  // cout << "In the DFS traverse, the current.numer is " << current->numer << ", it is root " << is_root << endl;

    pair<INT,INT> current_interval = {-10,-10};
	  // if(current_num > -1 && current_num < txt_size) {	// current is a leaf
	  if(current_num > -1) {	// current is a leaf

      // getting index to SA from invSA
      INT current_idx = inv_suffix_array[current_num];
      // Initialize the interval of the current node (leaf)

      current_interval = {current_idx,current_idx};
    }
    current->SA_interval = current_interval;
    // cout << "Current interval is [" << current_interval.first << "," << current_interval.second << "]" << endl;

	  // Push all the children to the traversal stack (in the order they appear)
    // cout << "children size = " << current->g.size() << endl;
	  for (auto const &child : current->g) {
      child_node = child.second.v;
      DFS_stack.push(child_node);
      INT child_edge_length = child.second.r - child.second.l + 1;

      INT child_str_depth = current_str_depth + child_edge_length;
      child_node->str_depth_of_N = child_str_depth;
      // cout <<"The numer of child_node is " << child_node->numer << ", the child_edge_length is " << child_edge_length << ", the child_str_depth is " << child_str_depth << endl; 
      child_node->parent = current;
    }

    // Push the current node to the result stack: Don't push the root, as well as the special char $
    // if (!is_root && current_num < txt_size) {
    if (!is_root) {
      // bottom_up_stack.push(current);
      rev_bottomup_ordered_nodes.push_back(current);
      // cout << "Now push the " << current->numer << " into the rev_bottomup_ordered_nodes!" << endl; 
    }

    if(current_num >= txt_size) outlier.push_back(current_num);
  }

	cout << "End DFS traverse, start bottom-up ordered traverse..." << endl;

  // Now, the nodes are in reverse post-order, so we need to process them in the correct order
  for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
    current = *it;
    bool is_root = current == r;

    // After the DFS traverse, only leaves have SA_interval
    if (current->SA_interval.first == -10 && current->SA_interval.second == -10) {
      INT current_min = numeric_limits<INT>::max(), current_max = numeric_limits<INT>::min();
      for (auto const &child : current->g) {
        if (child.second.v->SA_interval.first < current_min) {
          current_min = child.second.v->SA_interval.first;
        }
        if (child.second.v->SA_interval.second > current_max) {
          current_max = child.second.v->SA_interval.second;
        }
      }
      current->SA_interval = {current_min,current_max};
    }

    // Calculate the sum of the num_of_freq
    INT range_left = current->SA_interval.first, range_right = current->SA_interval.second;
    if(range_right - range_left + 1 >= freq_threshold && !is_root) {
      // current_path = current->path;
      parent_node = current->parent;
      INT parent_str_depth = parent_node->str_depth_of_N, cur_str_depth = current->str_depth_of_N;
      num_of_freq = num_of_freq + (cur_str_depth - parent_str_depth);
      // cout << "Now add " << cur_str_depth - parent_str_depth << " to num_of_freq, num_of_freq = " << num_of_freq << endl;
      freq_count++;
    }
  }

  return rev_bottomup_ordered_nodes;
}

IntervalTree<INT> is_periodic_preprocessing(unsigned char* text_string, INT text_size) {
    // const INT MAX_POINTS_DISPLAY = 20;
    // cout << "Go INTo the is_periodic_preprocessing function!" << endl;

    // Get all runs of S
    // string S(reinterpret_cast<const char*>(text_string), strlen(reinterpret_cast<const char*>(text_string)) - 1);
    // auto const R = linear_time_runs::compute_all_runs(S.data(), S.size());
    // Add two \1 before and after the text_string to ensure that the runs function run successfully
    unsigned char * sequence = ( unsigned char * ) malloc ( ( text_size+2 ) * sizeof ( unsigned char ) );
    sequence[0] = '\1';
    memcpy(sequence + 1, text_string, text_size);
    sequence[text_size+1] = '\1';


    auto const R = linear_time_runs::compute_all_runs(sequence, text_size+2);
    // INT poINTs_num = R.size();
    // cout << "\nString S contains " << poINTs_num << " runs:" << endl;
    free(sequence);

    // Create an interval tree
    IntervalTree<INT> tree;  
    for (auto run : R) {
      Interval<INT> cur = {run.start - 1, run.end - 1};
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



bool is_periodic(INT I, INT J, IntervalTree<INT>& interval_tree, INT &p) {
    Interval<INT> wantedInterval(I, J);
    const auto &outerIntervals = interval_tree.findOuterIntervals(wantedInterval);

    bool check_length = false;
    INT tmp_p = J - I + 1;
    // PrINT all intervals
    // cout << "Outer intervals for " << wantedInterval << ":" << endl;
    for (const auto &interval : outerIntervals) {
        INT per = interval.per;
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


INT greedy(vector<INT>& O, INT t, INT lamda) {
  // cout << "**********Into the Greedy function!**********" << endl;
  // if (t==1)
  //   return 1;
  INT k_prime_prime = 0, O_size = O.size();
  // cout << "O_size = " << O_size << ", lamda = " << lamda << ", t = " << t << endl;
  for (INT ell = 0; ell < O_size; ell++) {
    // cout << "The current ell = " << ell << endl;
    if (ell <= O_size - 2 && O[ell + 1] - O[ell] <= lamda - 1 && k_prime_prime < t) {
      // cout << "Kill a pair! O[ell + 1] = " << O[ell + 1] << ", O[ell] = " << O[ell] << endl;
      k_prime_prime ++;
      ell ++;
    }
  }
  INT k_prime = t - k_prime_prime;
  // cout << "k_prime = " << k_prime << ", k_prime_prime = " << k_prime_prime << ", return value is " << k_prime + 2 * k_prime_prime << endl;
  // cout << "************Greedy function end*************" << endl;
  
  return k_prime + 2 * k_prime_prime;
}


bool aperiodic_survive(STvertex* root, INT* &suffix_array, INT freq_threshold, INT k, INT l, INT r, INT I, INT J) {
  INT Occ = r - l + 1;
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
    vector<INT> O;
    for (INT i = l; i <= r; i++) {
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


vector<vector<INT>> create_clusters(INT* &suffix_array, INT l, INT r, INT p, INT max_H_size) {
  vector<INT> O;
  for (INT i = l; i <= r; i++) {
      O.push_back(suffix_array[i]);
  }
  sort(O.begin(), O.end());
  INT O_size = O.size();
  // cout << "The size of O set is " << O_size << endl;
  // for (auto const &item : O) {
  //   cout << item << " ";
  // }
  // cout << endl;

  vector<vector<INT>> H;
  vector<INT> current_cluster;
  current_cluster.push_back(O[0]);
  for(INT i = 1; i < O_size; i++) {
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

INT ceilDivision(INT a, INT b) {
    return (a + b - 1) / b;
}


bool periodic_survive(INT l, INT r, INT I, INT J, INT freq_threshold, INT k, vector<vector<INT>>& H, INT p) {
  // cout << "****************Into the periodic_survive function.**************" << endl;
  INT Occ = r - l + 1;
  // INT alpha = (J - I + 1) / p;
  INT alpha = ceilDivision(J - I + 1, p);
  // cout << "Occ = " << Occ << ", J - I + 1 = " << J - I + 1 << ", alpha = " << alpha << ", p = " << p << endl;

  vector<vector<INT>> cal_C;
  for (auto const &C : H) {
    INT C_size = C.size();
    INT mod_num = C_size % alpha;
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

  INT cal_C_size = cal_C.size();
  // cout << "cal_C_size = " << cal_C_size << endl;
  vector<INT> OV;
  OV.push_back(0);
  for (INT i = 1; i < cal_C_size; i++) {
    // cout << "i = " << i << ", cal_C[i - 1].size() - 1 = " << cal_C[i - 1].size() - 1<< ", cal_C[i - 1][cal_C[i - 1].size() - 1] = " << cal_C[i - 1][cal_C[i - 1].size() - 1] << ", cal_C[i][0] = " << cal_C[i][0] << endl;
    // OV[i] = max(cal_C[i - 1][cal_C[i - 1].size() - 1] + J - I + 1 - cal_C[i][0], 0);
    OV.push_back(max(cal_C[i - 1][cal_C[i - 1].size() - 1] + J - I + 1 - cal_C[i][0], (INT) 0));
  }
  // cout << "Now check the value of OV: " << endl;
  // for (INT i = 0; i < OV.size(); i++) {
  //   cout << OV[i] << " ";
  // }
  // cout << endl;

  vector<INT> cal_C_prime;
  INT curr = 0, i = 0; 
  priority_queue<INT> cal_D;
  // cout << "**********Start to check |C| mod alpha!**********" << endl;
  for (auto const &C : H) {
    INT C_size = C.size();
    INT mod_num = C_size % alpha;
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
      INT OV_value = OV[i];
      cal_D.push(C_size - 1);
      cal_C_prime.push_back(curr - OV_value);
      curr = curr - OV_value + J - I + 1;
      i++;
    }
    else if(mod_num == 2) {
      // cout << "Go INTo the case with mode = 2" << endl;
      // cout << "Push to cal_D with mode = 2" << endl;
      INT OV_value = OV[i];
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

  INT t = k, K = 0;
  while (!cal_D.empty() && t >= ceilDivision(cal_D.top(), alpha)) {
    // cout << "cal_D.top() = " << cal_D.top() << ", (cal_D.top() + alpha - 1) / alpha = " << (cal_D.top() + alpha - 1) / alpha << ", t = " << t << endl;
    K = K + cal_D.top();
    t = t - ceilDivision(cal_D.top(), alpha);
    cal_D.pop();
  }
  // cout << "Now t = " << t << ", K = " << K << endl;
  if(cal_D.empty() && t > 0) {
    K = K + greedy(cal_C_prime, t, J - I + 1);
  }
  if(!cal_D.empty() && t < cal_D.top() / alpha) {
    // cout << "Go INTo the t * alpha case!" << endl;
    K = K + t * alpha;
  }

  if(Occ - K >= freq_threshold) {
    // cout << "RETURN Survive! Occ = " << Occ << ", K = " << K << ", freq_threshold = " << freq_threshold << endl;
    return true;
  }

  return false;
}


bool check_freq_periodic_survive(bool is_node_checking, bool &is_cut_point, STvertex* r, STvertex* current, INT left, INT right, INT I, INT J, INT freq_threshold, INT k, INT* suffix_array, IntervalTree<INT>& interval_tree) {
  // cout << "current node's left = " << left << ", right = " << right << ", I = " << I << ", J = " << J << endl;
  
  bool periodic_survive_value = false, aperiodic_survive_value = false;
  // vector<STvertex*> current_path;
  vector<vector<INT>> H;
  
  if (right - left + 1 >= freq_threshold) {   // This is a \tau-frequent node
    // cout << "This node is frequent!" << endl;
    INT p = INT_MAX;
    bool is_periodic_value = is_periodic(I, J, interval_tree, p);  // Here p can store the return value from is_periodic when YES
    
    // cout << "The value of is_periodic is " << is_periodic_value << ", the p = " << p << endl;
    if (is_periodic_value) {
      // is_periodic_yes ++;   // Count the times of answering YES
      // First create the clusters H
      INT max_H_size = 2 * k + freq_threshold;
      H = create_clusters(suffix_array, left, right, p, max_H_size);

      // cout << "The clusters in the H are: " << endl;
      // for(auto const &C : H) {
      //   for(auto const &item : C) {
      //     cout << item << " ";
      //   }
      //   cout << endl;
      // }

      // Then call periodic_survive
      // cout << "Before INTo the periodic_survive, the p = " << p << endl;
      periodic_survive_value = periodic_survive(left, right, I, J, freq_threshold, k, H, p);

      // cout << "The value of periodic_survive is " << periodic_survive_value << endl;
      if (periodic_survive_value) {   // current is a node lying on the cut of ST
        if (is_node_checking) {   // Propagate upforward the status of frequent and survive to all ancestors except root
          is_cut_point = true;
          current->flag = true;
          // current_path = current->path;
          // INT current_path_length = current_path.size();
          // for (INT i = 1; i < current_path_length; i++) {   // Do not include the root
          //   current_path[i]->flag = true;
          // }
          STvertex *it = current;
          while (it != r) {
            it->parent->flag = true;
            it = it->parent;
          }
        }
      }
    }

    else {
      // is_periodic_no ++;   // Count the times of answering NO
      aperiodic_survive_value = aperiodic_survive(r, suffix_array, freq_threshold, k, left, right, I, J);

      // cout << "The value of aperiodic_survive is " << aperiodic_survive_value << endl;
      if (aperiodic_survive_value) {   // current is a node lying on the cut of ST
        if (is_node_checking) {   // Propagate upforward the status of frequent and survive to all ancestors except root
          is_cut_point = true;
          current->flag = true;
        //   current_path = current->path;
        //   INT current_path_length = current_path.size();
        //   for (INT i = 1; i < current_path_length; i++) {   // Do not include the root
        //     current_path[i]->flag = true;
        //   }
        // }
          STvertex *it = current;
          while (it != r) {
            it->parent->flag = true;
            it = it->parent;
          }
        }
      }
    }
  }

  return (aperiodic_survive_value || periodic_survive_value);
}

INT binary_search_longest_substring (INT low, INT high, INT I, INT child_l, INT child_r, INT freq_threshold, INT k, bool &is_cut_point, STvertex* &root, STvertex* &current, INT* &suffix_array, IntervalTree<INT>& interval_tree) {
  if (child_r - child_l + 1 < freq_threshold) {   // If the child node is not frequent, continue to the next child
    return low;
  }

  INT mid = 0, success_record = low;
  while (low < high) {
    mid = low + (high - low) / 2;     // mid is the floor INT
    if (mid == low) {
      bool is_freq_survive = check_freq_periodic_survive(false, is_cut_point, root, current, child_l, child_r, I, high, freq_threshold, k, suffix_array, interval_tree);
      if (is_freq_survive) {
        success_record = high;
      }
      break;
    }

    // cout << "current low = " << low << ", high = " << high << ", mid = " << mid << endl;
    bool is_freq_survive = check_freq_periodic_survive(false, is_cut_point, root, current, child_l, child_r, I, mid, freq_threshold, k, suffix_array, interval_tree);

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

    if(argv < 4) {
      cout << "Usage: ./main [text_file] [freq_threshold] [number of letter substitions]" << endl;
      return 1;
    }
    // Input text file
    ifstream is_text;
    string text_file = argc[1];

     // Input frequency threshold (tau)
    INT freq_threshold = stoi(argc[2]); 
    // Input the number of positions about letter replacements in S
    INT k = stoi(argc[3]); 


    // Find the position of the last '/'
    size_t pos = text_file.find_last_of("/");
    // Extract the substring after the last '/'
    string file_name = text_file.substr(pos + 1);
    string output_file = "output/st_" + file_name + "_" + to_string(freq_threshold) + "_" + to_string(k);

    // string text_file_path = "data/" + text_file;
    string text_file_path = text_file;

    // string text_file_path = "/scratch/prj/proj_loukides/github_useful_strings/useful_strings/" + text_file;

    cout << "text_file_path is " << text_file_path << endl;
    cout << "output_file is " << output_file << endl;

    cout << "tau = " << freq_threshold << ", k = " << k << endl;

    is_text.open (text_file_path, ios::in | ios::binary);
    
    ifstream in_file(text_file_path, ios::binary);
    in_file.seekg(0, ios::end);
    // INT text_file_size = in_file.tellg();
    INT text_file_size = in_file.tellg();

    
    unsigned char * text_string = ( unsigned char * ) malloc (  ( text_file_size+2 ) * sizeof ( unsigned char ) );
    char chr = 0;
    // INT text_size = 0;
    INT text_size = 0;
    
    string runtime_detail_csv = "runtime_details.csv";
    ofstream output_stream;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << "text_file,tau,k,read_txt,create_ST,create_SA,create_intervals,is_periodic_preprocess,find_cut,total\n";
    // // output_stream << "text_file,tau,k,total_runtime\n";
    // output_stream << text_file << "," << to_string(freq_threshold) << "," << to_string(k) << ",";
    // output_stream.close();

    // At the beginning and end of S, add two $ to ensure the all_run runs successfully!
    auto start = chrono::high_resolution_clock::now();
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
    // cout << "CHECK! The text_size = " << text_size << endl;
    // for(INT i = 0; i < text_size; i++) {
    //   cout << "char:" << (unsigned INT)text_string[i] << endl;
    // }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();

    auto whole_start = chrono::high_resolution_clock::now();

    start = chrono::high_resolution_clock::now();
    // InPlacePST ippst = is_periodic_preprocessing(text_string, text_size - 1);  // don't include the last char !
    IntervalTree<INT> runs = is_periodic_preprocessing(text_string, text_size);
    cout << "Construct all runs successfully!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;


    // return 0;   // Max RSS: 9197532

    
    // Pre-processing begin
    start = chrono::high_resolution_clock::now();
    STvertex *r = Create_suffix_tree( text_string , text_size );
    cout << "Create ST successfully! The number of leaves is " << liscie << endl;
    free(text_string);
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();

    start = chrono::high_resolution_clock::now();
    INT *suffix_array =(INT*) malloc(sizeof(INT) * text_size);
    build_suffix_array(suffix_array, text_size, r);
    cout << "Construct SA successfully!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();


    // cout<<"SA: ";
    // for(INT i=0; i<text_size; i++)
    //     cout<<suffix_array[i]<<" ";
    // cout<<endl;

    INT *inv_suffix_array =(INT*) malloc(sizeof(INT) * text_size);
    for(INT i=0; i<text_size; i++) {
      inv_suffix_array[suffix_array[i]] = i;
    }

    // return 0;    // Max RSS: 63239776


    start = chrono::high_resolution_clock::now();
    vector<STvertex*> rev_bottomup_ordered_nodes = bottom_up_SA_interval(r, suffix_array, inv_suffix_array, text_size, freq_threshold);
    cout << "Construct SA interval for each node in ST successfully. Preprocessing end!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();
    free(inv_suffix_array);
    // Pre-processing end

    // cout << "The num_of_freq = " << num_of_freq << ", outlier.size = " << outlier.size() << endl;
    // for(const auto &item : outlier) {
    //   cout << item << " ";
    // }
    // cout << endl;
    
    // return 0;    // Max RSS: 67435236


    // Start MAIN ALGORITHM
    // map<unsigned char,STedge,greater<unsigned char>> children_map;
	  STvertex* current = r;
    STvertex* child_node;
    STvertex* parent_node;
    vector<STvertex*> current_path;
    INT *OUTPUT =(INT*) malloc(sizeof(INT) * text_size);
    for (INT i = 0; i < text_size; i++) {
      OUTPUT[i] = 0;
    }

	  cout << "Start to find the cut!" << endl;
    // cout << "The size of bottom_up_ordered_nodes is " << rev_bottomup_ordered_nodes.size() << ", text_size = " << text_size << endl;
    // Now, the nodes are in reverse post-order, so we need to process them in the correct order
    start = chrono::high_resolution_clock::now();
    for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
      current = *it;
      
      bool is_cut_point = false, is_freq_survive = false;

      INT cur_left = current->SA_interval.first, cur_right = current->SA_interval.second;
      if (cur_right - cur_left + 1 < freq_threshold) {  // If the current node is not frequent, continue to the next current
          continue;
      }

      parent_node = current->parent;
      INT parent_str_depth = parent_node->str_depth_of_N, current_str_depth = current->str_depth_of_N;
      if(current->flag) {   // This node is the ancestor of a cut node u
        num_of_resi = num_of_resi + current_str_depth - parent_str_depth;
        // cout << "Now add child_str_len " << current_str_depth - parent_str_depth << " to num_of_resi, num_of_resi = " << num_of_resi << endl;

        for (auto const &child : current->g) {
          child_node = child.second.v;
          // vector<INT> child_SA_interval = child_node->SA_interval;
          INT child_l = child_node->SA_interval.first, child_r = child_node->SA_interval.second;
          // cout << "child_l = " << child_l << ", child_r = " << child_r << endl;
          INT child_str_depth = child_node->str_depth_of_N; 
          
          if (child_node->flag) {
            continue;
          }
          else {    // This child node is v
            INT I = suffix_array[child_l], J; // left bound of the substring is fixed, we need to find out the right bound
            INT low = I + current_str_depth - 1, high = I + child_str_depth - 1;
            J = binary_search_longest_substring(low, high, I, child_l, child_r, freq_threshold, k, is_cut_point, r, current, suffix_array, runs);
            INT refined_cut_len = J - I + 1;

            for (INT i = child_l; i <= child_r; i++) {
              // cout << "The OUTPUT for index (suffix_array[i]) " << suffix_array[i] << " is " << refined_cut_len << endl;
              OUTPUT[suffix_array[i]] = refined_cut_len;
            }

            num_of_resi = num_of_resi + J - low;

            resi_count++;
            // cout << "Now add (a)J - low = " << J - low << " to num_of_resi, num_of_resi = " << num_of_resi << endl;
          }
        }
      }
      else {
        // cout << "Start to find the first cut node!" << endl;
        
        INT I = suffix_array[cur_left];
        INT J = I + current_str_depth - 1;
        
        is_freq_survive = check_freq_periodic_survive(true, is_cut_point, r, current, cur_left, cur_right, I, J, freq_threshold, k, suffix_array, runs);

        if (is_cut_point) {
          // cout << "*********This is a cut node! Start binary search to find out the refined cut!********" << endl;

          num_of_resi = num_of_resi + current_str_depth - parent_str_depth;
          // cout << "Now add " << current_str_depth - parent_str_depth << " to num_of_resi, num_of_resi = " << num_of_resi << endl;
          
          is_freq_survive = false;
          for (auto const &child : current->g) {
            child_node = child.second.v;
            // vector<INT> child_SA_interval = child_node->SA_interval;
            INT child_l = child_node->SA_interval.first, child_r = child_node->SA_interval.second;
            INT child_str_depth = child_node->str_depth_of_N;
            
            INT I = suffix_array[child_l], J; // left bound of the substring is fixed, we need to find out the right bound
            INT low = I + current_str_depth - 1, high = I + child_str_depth - 1;
            J = binary_search_longest_substring(low, high, I, child_l, child_r, freq_threshold, k, is_cut_point, r, current, suffix_array, runs);
            INT refined_cut_len = J - I + 1;
            
            // cout << "Current child's [l,r] is [" << child_l << "," << child_r << "]" << endl;
            for (INT i = child_l; i <= child_r; i++) {
              // cout << "The OUTPUT for index (suffix_array[i]) " << suffix_array[i] << " is " << refined_cut_len << endl;
              OUTPUT[suffix_array[i]] = refined_cut_len;
            }

            num_of_resi = num_of_resi + J - low;
            // cout << "Now add (b)J - low = " << J - low << " to num_of_resi, num_of_resi = " << num_of_resi << endl;
          }
        }
      }
    }
  end = chrono::high_resolution_clock::now();
  elapsed = end - start;
  // output_stream.open(runtime_detail_csv, ios::app);
  // output_stream << elapsed.count() << ",";
  // output_stream.close();

  // Clear suffix array, suffix tree and interval tree
  free(suffix_array);
  runs.clear();
  // STDelete(r);
  // STDelete(root);
  for (auto it = rev_bottomup_ordered_nodes.rbegin(); it != rev_bottomup_ordered_nodes.rend(); ++it) {
    delete *it;
  }
  cout << "Delete the ST" << endl;

  // cout << "freq_count = " << freq_count << ", bottomup vector.size = " << rev_bottomup_ordered_nodes.size() << endl;
  rev_bottomup_ordered_nodes.clear();

  auto whole_end = chrono::high_resolution_clock::now();
  chrono::duration<double> whole_elapsed = whole_end - whole_start;
  cout << "The whole process takes " << whole_elapsed.count() << " s." << endl;
  cout << "The num_of_freq = " << num_of_freq << ", num_of_resi = " << num_of_resi << ", num_of_resi / num_of_freq = " << (double) num_of_resi / (double) num_of_freq << ", num_of_freq - num_of_resi = " << num_of_freq - num_of_resi << endl;

  // output_stream.open(runtime_detail_csv, ios::app);
  // output_stream << whole_elapsed.count() << "\n";
  // output_stream.close();

  
  // output_stream.open(output_file);
  output_stream.open("st_output");
  if(!output_stream.is_open()) {
        cout << "Couldn't open output file\n" << endl; 
  }
  // cout << "The OUTPUT with size " << text_size - 2 << " is ";
  // for(INT i = 1; i < text_size - 2; i++) {  // Exclude the first and last special char
  for(INT i = 0; i < text_size - 1; i++) {  // Exclude the first and last special char
    // cout << OUTPUT[i] << " ";
    output_stream << OUTPUT[i] << "\n";
  }
  // cout << endl;
  output_stream.close();
  free(OUTPUT);

  // if(freq_threshold == 2) num_of_freq--;    // Remove the case of two \1 at the beginning and end of string S
  
  cout << "Finish!\n" << endl;

  // cout << "\nThe count of is_periodic_yes = " << is_periodic_yes << ", count of is_periodic_no = " << is_periodic_no << endl;


  return 0;
}