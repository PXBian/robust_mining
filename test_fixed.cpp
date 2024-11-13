#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <fstream>
#include <stack>
#include <fstream>
#include <bitset>
#include <string>


using namespace std;

int main(int argc, char **argv) {
	const int num_bits = 10;  // Number of bits in each binary string
    const int total_strings = 1 << num_bits; // Total number of strings (2^16 = 65536)
    
    for (int i = 0; i < total_strings; ++i) {
        // Convert the integer to a binary string of 16 digits
        bitset<num_bits> binary_string(i);
        
        // Create a filename for each binary string, e.g., "binary_00001.txt"
        string filename = "binary_test.txt";
        string pathname = "data/" + filename;
        
        // Open the file and write the binary string to it
        string current_str = binary_string.to_string();
        ofstream outfile(pathname);
        if (outfile.is_open()) {
            outfile << current_str << endl;
            outfile.close();
        } else {
            cerr << "Failed to open file: " << pathname << endl;
        }

        // Start to execute baseline
        for (int tau = 2; tau <= 6; tau++) {
            for (int k = 1; k <= 8; k++) {
                string command_str = "rm runtime_details.csv";
                const char* command = command_str.c_str();
                system(command);

                command_str = "./baseline " + pathname + " " + to_string(k) + " " + to_string(tau) + " baseline_output";
                command = command_str.c_str();
                system(command);

                command_str = "./esa " + pathname + " " + to_string(tau) + " " + to_string(k);
                command = command_str.c_str();
                system(command);

                ifstream output_file;
                ofstream result_file;
                vector<int> baseline_vec, main_vec;
                string file_line;
                int cur_num;

                output_file.open("baseline_output");
                if (output_file.is_open()) {
                    while (getline(output_file, file_line)) {
                        cur_num = stoi(file_line);
                        baseline_vec.push_back(cur_num);
                    }
                }
                output_file.close();

                output_file.open("main_output");
                if (output_file.is_open()) {
                    while (getline(output_file, file_line)) {
                        cur_num = stoi(file_line);
                        main_vec.push_back(cur_num);
                    }
                }
                output_file.close();

                // if (tau == 2 && k == 1 && current_str == "100100") {
                //     baseline_vec = {1,1,1,1,1,1};
                //     main_vec = {1,1,0,1,1,1};
                // }
                

                result_file.open("testing_results_summary", fstream::app);
                if (baseline_vec.size() != main_vec.size()) {
                    cout << "the size of baseline_vec is" << baseline_vec.size() << ", main_vec is" << main_vec.size() << endl;
                    result_file << current_str << ", tau=" << tau << ", k=" << k << ": The output sizes do not matched!\n";
                    result_file.close();
                    continue;
                }


                for (int i = 0; i < baseline_vec.size(); i++) {
                    if (baseline_vec[i] != main_vec[i]) {
                        result_file << current_str << ", tau=" << tau << ", k=" << k << ": The outputs does not matched!\n";
                        command_str = "mv baseline_output error_bl_" + current_str + "_" + to_string(tau) + "_" + to_string(k);
                        command = command_str.c_str();
                        system(command);

                        command_str = "mv main_output error_main_" + current_str + "_" + to_string(tau) + "_" + to_string(k);
                        command = command_str.c_str();
                        system(command);
                        result_file.close();
                        break;
                    }
                }
                result_file.close();
            }
        }
        
    }
    
    cout << "All 16-digit binary strings have been written to separate files." << endl;
    
    return 0;
}