#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <string>
#include <random>
#include <fstream>


using namespace std;

string generateRandomBinaryString() {
    // Random number generator for length (between 1 and 100)
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister generator
    uniform_int_distribution<> lengthDist(1, 100); // Length between 1 and 100

    // Generate random length
    int length = lengthDist(gen);

    // Random binary generator (0 or 1)
    uniform_int_distribution<> binaryDist(0, 1);

    // Generate the binary string
    string binaryString;
    for (int i = 0; i < length; ++i) {
        binaryString += (binaryDist(gen) == 0 ? '0' : '1');
    }

    return binaryString;
}

int main(int argc, char **argv) {
	
    // int count = 20;
    while (1) {
        // Create a filename for each binary string, e.g., "binary_00001.txt"
        string filename = "binary_test.txt";
        string pathname = "data/" + filename;
        
        // Open the file and write the randomly generated binary string to it
        string current_str = generateRandomBinaryString();
        ofstream outfile(pathname);
        if (outfile.is_open()) {
            outfile << current_str << endl;
            outfile.close();
        } else {
            cerr << "Failed to open file: " << pathname << endl;
        }

        int str_length = current_str.length();
        int tau = 2 + rand() % str_length;
        int k = 1 + rand() % str_length;
        cout << "The current string is " << current_str << endl;
        cout << "The str length is " << str_length << ", tau = " << tau << ", k = " << k << endl;


        string command_str = "./baseline " + pathname + " " + to_string(k) + " " + to_string(tau) + " baseline_output";
        const char* command = command_str.c_str();
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
    
    return 0;
}