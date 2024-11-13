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
#include <sdsl/suffix_trees.hpp>

#include "runs.hpp"
#include "intervaltree.hpp"
// #include "suffixtree.hpp"

using namespace std;
using namespace Intervals;
typedef int32_t INT;


// INT is_periodic_yes = 0, is_periodic_no = 0;
INT num_of_freq = 0, num_of_resi = 0;

/* LCP array construction algorithm in O(n) time (Kasai et al.) */
unsigned int LCParray ( unsigned char * text, INT n, INT * SA, INT * ISA, vector<INT>& LCP )
{										
	INT j = 0;
	LCP[0] = 0;
	for ( INT i = 0; i < n; i++ ) // compute LCP[ISA[i]]
		if ( ISA[i] != 0 ) 
		{
			if ( i == 0) j = 0;
			else j = (LCP[ISA[i-1]] >= 2) ? LCP[ISA[i - 1]] -1 : 0;
			while ( text[i+j] == text[SA[ISA[i]-1]+j] )	j++;
			LCP[ISA[i]] = j;
		}
	return ( 1 );
}

/* This is the struct we use for the tuples */
struct B { short int FLAG = (short int)0; INT l = 0; INT r = 0; INT lcp = 0; INT parent = -1; vector<INT> ch;};
/* This is the comparator for sorting tuples by l */
bool tuples_sorter(B const& lhs, B const& rhs) 
{
    return (lhs.r - lhs.l) > (rhs.r - rhs.l);
    // return lhs.parent < rhs.parent;
}

/* We construct one tuple for every internal node of the suffix tree in O(n) time */
unsigned int construct_tuples ( INT n, INT * SA, vector<B>& b, vector<INT>& LCP, vector<INT>& bottomup_order)
{
	stack<INT> st;

	INT x = -1;		// lastInterval in the Algorithm 4.4
	b[0].lcp = 0;
  b[0].l = 0; // Here we push the root node
  b[0].r = -1;
  b[0].ch.clear();
	// cout << "b[0].lcp=" << b[0].lcp << endl;
	st.push(0);

  
  for(INT i = 1; i < n; i++) 		// This for loop simulates a suffix tree DFS traversal using the LCP array
	{
    INT l = i - 1;
    
  	while (LCP[i] < LCP[st.top()]) //b[st.top()].lcp
		{
			// cout << "Go into the WHILE loop!" << endl;
      x = st.top();	// The index of the lastInterval
      b[x].r = i - 1; 
      st.pop();
      
      l = b[x].l; 

      bottomup_order.push_back(x);
      INT check_top = st.top();
      if (LCP[i] <= LCP[check_top]) 
			{
        // cout << "check_top=" << check_top << endl;
        b[check_top].ch.push_back(x);
        b[x].parent = check_top;
				// cout << "Push x=" << x << " to b[st.top()].ch, where b[st.top()].l=" << b[check_top].l << ", b[st.top()].r=" << b[check_top].r << endl;
				x = -1;
      }
    }
  	if (LCP[i] > LCP[st.top()]) 
		{
			// cout << "Go into the IF! LCP[i]=" << LCP[i] << ", l=" << l << endl;
      b[i].lcp = LCP[i];
      b[i].l = l;
			b[i].r = -1;
      b[i].ch.clear();
			st.push(i); 

			// if (~ x) // x == -1: ~-1 = 0, FALSE. x is the index of b[], x=0 means this is the root
      if(x != -1)
			{
				b[i].ch.push_back(x);
        b[x].parent = i;
				// cout << "Push x=" << x << " to b[i].ch, where b[i].l=" << b[i].l << ", b[i].r=" << b[i].r << endl;

				x = -1;
      }
     }
    }

	cout << "Tuples corresponding to internal nodes are constructed." << endl;
    	
	return (1);
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

    // cout<<"String sequence with length " << text_size + 2 << "is ";
    // for(INT i=0; i<text_size + 2; i++) {
    //   cout<< sequence[i] << ":" << (INT) sequence[i] << " ";
    // }
    // cout << endl;

    
    auto const R = linear_time_runs::compute_all_runs(sequence, text_size+2);
    // INT poINTs_num = R.size();
    // cout << "\nString S contains " << poINTs_num << " runs:" << endl;
    free(sequence);


    // IntervalTree<INT> tmp;
    // return tmp;


    // Create an interval tree
    IntervalTree<INT> tree;  
    for (auto run : R) {
      Interval<INT> cur = {run.start - 1, run.end - 1};
      cur.per = run.period;
      tree.insert(cur);
      // cout << "start=" << run.start - 1
      //      << ", end=" <<  run.end - 1
      //      << ", per=" << run.period
      //      << ", len=" << run.length
      //      << ", exp=" << run.length / (double) run.period
      //      << ", str=" << S.substr(run.start - 1, run.length) << endl;
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


bool aperiodic_survive(INT* &suffix_array, INT freq_threshold, INT k, INT l, INT r, INT I, INT J) {
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


bool check_freq_periodic_survive(bool is_node_checking, bool &is_cut_point, vector<B>& b, INT cur_index, INT left, INT right, INT I, INT J, INT freq_threshold, INT k, INT* suffix_array, IntervalTree<INT>& interval_tree) {
  // cout << "current node's left = " << left << ", right = " << right << ", I = " << I << ", J = " << J << endl;
  
  bool periodic_survive_value = false, aperiodic_survive_value = false;
  // vector<STvertex*> current_path;
  vector<vector<INT>> H;
  
  if (right - left + 1 >= freq_threshold) {   // This is a \tau-frequent node
    // cout << "This node is frequent!" << endl;
    INT p = INT_MAX;
    bool is_periodic_value = is_periodic(I, J, interval_tree, p);  // Here p can store the return value from is_periodic when YES
    
    // B current = b[cur_index];
    // cout << "The value of is_periodic is " << is_periodic_value << ", the p = " << p << endl;
    if (is_periodic_value) {
      // is_periodic_yes ++;   // Count the times of answering YES
      // First create the clusters H
      INT max_H_size = 2 * k + freq_threshold;
      H = create_clusters(suffix_array, left, right, p, max_H_size);


      periodic_survive_value = periodic_survive(left, right, I, J, freq_threshold, k, H, p);

      // cout << "The value of periodic_survive is " << periodic_survive_value << endl;
      if (periodic_survive_value) {   // current is a node lying on the cut of ST
        if (is_node_checking) {   // Propagate upforward the status of frequent and survive to all ancestors except root
          is_cut_point = true;
          b[cur_index].FLAG = (short int)1;

          // cout << "Start to upforward the FLAG" << endl;
          // B it = b[cur_index];
          INT it = cur_index;
          while (it != 0) {    // This is not the root
            // cout << "it.parent = " << it.parent << endl;
            INT parent_index = b[it].parent;
            b[parent_index].FLAG = (short int)1;
            it = parent_index;
          }
        }
      }
    }

    else {
      // is_periodic_no ++;   // Count the times of answering NO
      aperiodic_survive_value = aperiodic_survive(suffix_array, freq_threshold, k, left, right, I, J);

      // cout << "The value of aperiodic_survive is " << aperiodic_survive_value << endl;
      if (aperiodic_survive_value) {   // current is a node lying on the cut of ST
        if (is_node_checking) {   // Propagate upforward the status of frequent and survive to all ancestors except root
          is_cut_point = true;
          b[cur_index].FLAG = (short int)1;


          // // cout << "Start to upforward the FLAG" << endl;
          // B it = current;
          // while (it.parent != -1) {
          //   // cout << "it.parent = " << it.parent << endl;
          //   b[it.parent].FLAG = (short int)1;
          //   it = b[it.parent];
          // }

          INT it = cur_index;
          while (it != 0) {    // This is not the root
            // cout << "it.parent = " << it.parent << endl;
            INT parent_index = b[it].parent;
            b[parent_index].FLAG = (short int)1;
            it = parent_index;
          }
        }
      }
    }
  }

  return (aperiodic_survive_value || periodic_survive_value);
}



INT binary_search_longest_substring (INT low, INT high, INT I, INT child_l, INT child_r, INT freq_threshold, INT k, bool &is_cut_point, vector<B>& b, INT cur_index, INT* &SA, IntervalTree<INT>& interval_tree) {
  if (child_r - child_l + 1 < freq_threshold) {   // If the child node is not frequent, continue to the next child
    return low;
  }

  INT mid = 0, success_record = low;
  while (low < high) {
    mid = low + (high - low) / 2;     // mid is the floor INT
    if (mid == low) {
      bool is_freq_survive = check_freq_periodic_survive(false, is_cut_point, b, cur_index, child_l, child_r, I, high, freq_threshold, k, SA, interval_tree);
      if (is_freq_survive) {
        success_record = high;
      }
      break;
    }

    // cout << "current low = " << low << ", high = " << high << ", mid = " << mid << endl;
    bool is_freq_survive = check_freq_periodic_survive(false, is_cut_point, b, cur_index, child_l, child_r, I, mid, freq_threshold, k, SA, interval_tree);

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
    string output_file = "output/esa_" + file_name + "_" + to_string(freq_threshold) + "_" + to_string(k);

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
    cout << "text_file_size=" << text_file_size << endl;

    
    unsigned char * text_string = ( unsigned char * ) malloc (  ( text_file_size+2 ) * sizeof ( unsigned char ) );
    char chr = 0;
    // INT text_size = 0;
    INT text_size = 0;
    
    ofstream output_stream;


    // At the beginning and end of S, add two $ to ensure the all_run runs successfully!
    auto start = chrono::high_resolution_clock::now();
    // text_string[0] = '\1';
    // cout << "text_file_size is " << text_file_size << ", start reading! " << endl;
    // for (INT i = 1; i <= text_file_size; i++) {	
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

    // cout << "Text num of length n = " << text_size - 1 << "." << endl;

	  // cout<<"Text string is ";
    // for(INT i=0; i<text_size; i++)
    //     cout<< text_string[i] << " ";
   	// cout<<endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();

    // return 0;   //Max RSS: 208128

    auto whole_start = chrono::high_resolution_clock::now();

    // Check if a substring is periodic, and return its period if it is periodic
    // Find all runs of S, and store it in an interval tree
    start = chrono::high_resolution_clock::now();
    // InPlacePST ippst = is_periodic_preprocessing(text_string, text_size - 1);  // don't include the last char !
    IntervalTree<INT> runs = is_periodic_preprocessing(text_string, text_size);
    cout << "Construct all runs successfully!" << endl;
    end = chrono::high_resolution_clock::now();
    elapsed = end - start;
    // output_stream.open(runtime_detail_csv, ios::app);
    // output_stream << elapsed.count() << ",";
    // output_stream.close();
    

    // return 0;    // Max RSS: 9402032


    cout << "Start to build SA and LCP" << endl;
    INT * SA = ( INT * ) malloc( ( text_size ) * sizeof( INT ) );
    vector<INT> LCP(text_size, 0);

    /*Compute the SA array */
    if( divsufsort( text_string, SA,  text_size ) != 0 )
    {
      fprintf(stderr, " Error: SA computation failed.\n" );
      exit( EXIT_FAILURE );
    }

    /*Compute the inverse SA array */
    INT * invSA = ( INT * ) calloc( text_size , sizeof( INT ) );
    if( ( invSA == NULL) )
    {
            fprintf(stderr, " Error: Cannot allocate memory for invSA.\n" );
            return ( 0 );
    }
    for ( INT i = 0; i < text_size; i ++ )	invSA [SA[i]] = i;

    /* Compute the LCP array */
    if( LCParray( text_string, text_size, SA, invSA, LCP ) != 1 )
    {
            fprintf(stderr, " Error: LCP computation failed.\n" );
            exit( EXIT_FAILURE );
    }
    free ( invSA );
    cout << "SA and LCP array are constructed." << endl;
    free(text_string);

    // cout << "SA is " << endl;
    //   for (int i = 0; i < text_size; i++) {
    //     cout << SA[i] << " ";
    //   }
    // cout << endl;


    // cout << "LCP is " << endl;
    //   for (int i = 0; i < text_size; i++) {
    //     cout << LCP[i] << " ";
    //   }
    // cout << endl;


    // return 0;   //Max RSS: 9402300

    
	  // B * b = ( B * ) realloc(b, ( text_size ) * sizeof( B ) );
	  vector<B> b(text_size);

    // return 0;   //Max RSS: 18062704


    vector<INT> bottomup_order;
    construct_tuples (text_size, SA, b, LCP, bottomup_order);
    LCP.clear();
    // cout << "Free LCP" << endl;

    // cout << "The bottom-up order are " << endl;
    // for (const auto &item : bottomup_order) {
    //   cout << item << " ";
    // }
    // cout << endl;

    // return 0;     //Max RSS: 21421224

    // cout << "The tuples before are " << endl;
    // for (int i = 0; i < text_size; i++) {
    //   cout << "i=" << i << ", l=" << b[i].l << ", r=" << b[i].r << ", lcp=" << b[i].lcp << ", flag=" << b[i].FLAG << ", parent=" << b[i].parent << ", children are: ";
    //   for (const auto &child: b[i].ch) {
    //     cout << child << ",";
    //   }
    //   cout << endl;
    // }

    
    INT last_index = -1;
    for(const auto cur_index : bottomup_order) {
      // cout << "cur_index=" << cur_index << ", last_index=" << last_index << endl;
  
      //  CASE I: Start to traverse: Add all the leaves of b[cur_index]
      if(last_index == -1) {     
        // cout << "BU is empty case" << endl;
        // cout << "b[cur_index].l=" << b[cur_index].l << ", b[cur_index].r=" << b[cur_index].r << endl;
        for(INT a = b[cur_index].l; a <= b[cur_index].r; a++) {
          // complete_BU_order.push_back({a,a});
          b[cur_index].ch.push_back(-a);
          // cout << "in=" << a << " ";
        }
        // cout << endl;
      }
      // CASE II: b[cur_index] is disjoint with the last interval (They have same parent)
      else if (b[last_index].r < b[cur_index].l) {
        // cout << "Disjoint case" << endl;

        // for (INT a = b[last_index].r + 1; a <= b[cur_index].r; a++) {
        for (INT a = b[cur_index].l; a <= b[cur_index].r; a++) {

          // complete_BU_order.push_back({a,a});
          b[cur_index].ch.push_back(-a);
          // cout << "d=" << a << " ";
        }
        // cout << endl;
      }
      // CASE III: b[cur_index] includes the last interval (cur is the parent of last)
      else {
        // cout << "Include case" << endl;
        vector<INT> gaps;

        // (a): Check for uncovered points after the first child interval
        for (INT a = b[cur_index].l; a < b[b[cur_index].ch[0]].l; a++) { 
          // cout << "a=" << a << endl;
          gaps.push_back(a);
        }  
        // (b): Check for uncovered points between consecutive child intervals
        for (INT ch_count = 1; ch_count < b[cur_index].ch.size(); ch_count++) {
          for (int j = b[b[cur_index].ch[ch_count-1]].r + 1; j < b[b[cur_index].ch[ch_count]].l; j++) {
            // cout << "j=" << j << endl;
              gaps.push_back(j);
          }
        }  
        // (c): Check for uncovered points after the last child interval
        for (int a = b[last_index].r + 1; a <= b[cur_index].r; a++) {
          // cout << "A=" << a << endl;
          gaps.push_back(a);
        }

        for (const auto &a: gaps) {
          // cout << "a=" << a << " ";
          // complete_BU_order.push_back({a,a});
          b[cur_index].ch.push_back(-a);
        }
        // cout << endl;

        gaps.clear();
      }

      // Calculate the sum of the num_of_freq
      INT range_left = b[cur_index].l, range_right = b[cur_index].r;
      if(range_right - range_left + 1 >= freq_threshold && cur_index != 0) {
        // current_path = current->path;
        INT parent_index = b[cur_index].parent;
        INT parent_str_depth = b[parent_index].lcp, cur_str_depth = b[cur_index].lcp;
        num_of_freq = num_of_freq + (cur_str_depth - parent_str_depth);
        // cout << "Now add " << cur_str_depth - parent_str_depth << " to num_of_freq, num_of_freq = " << num_of_freq << endl;
      }

      last_index = cur_index;
    }

    // cout << "The tuples are " << endl;
    // for (int i = 0; i < text_size; i++) {
    //   cout << "i=" << i << ", l=" << b[i].l << ", r=" << b[i].r << ", lcp=" << b[i].lcp << ", flag=" << b[i].FLAG << ", parent=" << b[i].parent << ", children are: ";
    //   for (const auto &child: b[i].ch) {
    //     cout << child << ",";
    //   }
    //   cout << endl;
    // }


    // return 0;     //Max RSS: 16742976


    // Start MAIN algorithm
    INT *OUTPUT =(INT*) malloc(sizeof(INT) * text_size);
    for (INT i = 0; i < text_size; i++) {
      OUTPUT[i] = 0;
    }

	  cout << "Start to find the cut!" << endl;
    for (const auto &index : bottomup_order) {
      // cout << "Current index = " << index << endl;
      bool is_cut_point = false, is_freq_survive = false;
      B current = b[index];
      INT current_str_depth = current.lcp;
      INT cur_left = current.l, cur_right = current.r;
      // pair<INT,INT> cur_interval = make_pair(cur_left, cur_right);
      
      // cout << "Current index = " << index << ", [" << cur_left << "," << cur_right << "], flag = " << FLAG[index] << endl;

      if(cur_right - cur_left + 1 < freq_threshold) {
        // cout << "Current is not frequent!" << endl;
        continue;
      }

      // cout << "Current is frequent!" << endl;
      INT parent_index = b[index].parent;
      INT parent_str_depth = b[parent_index].lcp, cur_str_depth = b[index].lcp;
      if(b[index].FLAG) {    // This node is the ancestor of a cut node u
        num_of_resi = num_of_resi + (cur_str_depth - parent_str_depth);
        for(const auto &ch_idx : current.ch) {
          
          // if (child_r > rightmost) {
          //   rightmost = child_r;
          // }
          if (ch_idx > 0 && b[ch_idx].FLAG) {
            // cout << "Child index " << ch_idx << " FLAG is TRUE!" << endl;
            
            continue;
          }
          else {
            INT child_l, child_r, child_str_depth;
            if (ch_idx > 0) {   // Child is a branching node
              B child_node = b[ch_idx];
              child_l = child_node.l, child_r = child_node.r;
              child_str_depth = child_node.lcp;
              // children_intervals.push_back(make_pair(child_l, child_r));
              // cout << " Branching: Current child's [l,r] is [" << child_l << "," << child_r << "], its str_depth=" << child_str_depth << endl;
            }
            else {            // Child is a leaf
              child_l = -ch_idx, child_r = -ch_idx;
              child_str_depth = text_size - SA[-ch_idx] - 1;
              // cout << " Leaf: Current child's [l,r] is [" << child_l << "," << child_r << "], its str_depth=" << child_str_depth << endl;
            }

            INT I = SA[child_l], J;
            INT low = I + current_str_depth - 1, high = I + child_str_depth - 1;
            J = binary_search_longest_substring(low, high, I, child_l, child_r, freq_threshold, k, is_cut_point, b, index, SA, runs);
            
            INT refined_cut_len = J - I + 1;
            // INT refined_cut_len = min(J, text_size - 2) - I + 1;
            for (INT i = child_l; i <= child_r; i++) {
              // cout << "The OUTPUT for index (SA[i]) " << SA[i] << " is " << refined_cut_len << endl;
              OUTPUT[SA[i]] = refined_cut_len;
            }

            num_of_resi = num_of_resi + J - low;
          }
        }
      }
      else {
        // cout << "Start to find the first cut node!" << endl;
        // vector<pair<INT,INT>> children_intervals;
        
        INT I = SA[cur_left];
        INT J = I + current_str_depth - 1;

        is_freq_survive = check_freq_periodic_survive(true, is_cut_point, b, index, cur_left, cur_right, I, J, freq_threshold, k, SA, runs);
        if (is_cut_point) {
          // cout << "This is a cut node!" << endl;

          num_of_resi = num_of_resi + (cur_str_depth - parent_str_depth);

          is_freq_survive = false;
          for (auto const &ch_idx : current.ch) {
            INT child_l, child_r, child_str_depth;
            if (ch_idx > 0) {   // Child is a branching node
              B child_node = b[ch_idx];
              child_l = child_node.l, child_r = child_node.r;
              child_str_depth = child_node.lcp;
              // children_intervals.push_back(make_pair(child_l, child_r));
              // cout << "Branching: Current child's [l,r] is [" << child_l << "," << child_r << "], its str_depth=" << child_str_depth << endl;
            }
            else {            // Child is a leaf
              child_l = -ch_idx, child_r = -ch_idx;
              child_str_depth = text_size - SA[-ch_idx] - 1;
              // cout << "Leaf: Current child's [l,r] is [" << child_l << "," << child_r << "], its str_depth=" << child_str_depth << endl;
            }
            
            INT I = SA[child_l], J; // left bound of the substring is fixed, we need to find out the right bound
            INT low = I + current_str_depth - 1, high = I + child_str_depth - 1;
            J = binary_search_longest_substring(low, high, I, child_l, child_r, freq_threshold, k, is_cut_point, b, index, SA, runs);
            INT refined_cut_len = J - I + 1;
            
            
            // cout << "Current child's [l,r] is [" << child_l << "," << child_r << "]" << endl;
            for (INT i = child_l; i <= child_r; i++) {
              // cout << "The OUTPUT for index (SA[i]) " << SA[i] << " is " << refined_cut_len << endl;
              OUTPUT[SA[i]] = refined_cut_len;
            }

            num_of_resi = num_of_resi + J - low;
            // cout << "Now add (b)J - low = " << J - low << " to num_of_resi, num_of_resi = " << num_of_resi << endl;
          }
        } 
      }
    }

    cout << "Finish MAIN-ESA algorithm!" << endl;

    free(SA);
    bottomup_order.clear();
    b.clear();
    // cout << "Free all the data storage" << endl;
    cout << "The num_of_freq = " << num_of_freq << ", num_of_resi = " << num_of_resi << ", num_of_resi / num_of_freq = " << (double) num_of_resi / (double) num_of_freq << ", num_of_freq - num_of_resi = " << num_of_freq - num_of_resi << endl;


    auto whole_end = chrono::high_resolution_clock::now();
    chrono::duration<double> whole_elapsed = whole_end - whole_start;
    cout << "The whole process takes " << whole_elapsed.count() << " s." << endl;

    // output_stream.open(output_file);
    output_stream.open("main_output");
    if(!output_stream.is_open()) {
          cout << "Couldn't open output file\n" << endl; 
    }
    // cout << "The OUTPUT with size " << text_size - 1 << " is ";
    for(INT i = 0; i < text_size - 1; i++) {  // Exclude the first and last special char
      // cout << OUTPUT[i] << " ";
      output_stream << OUTPUT[i] << "\n";
    }
    // cout << endl;
    output_stream.close();
    free(OUTPUT);
  
    cout << "Finish!\n" << endl;

  // cout << "\nThe count of is_periodic_yes = " << is_periodic_yes << ", count of is_periodic_no = " << is_periodic_no << endl;


  return 0;
}