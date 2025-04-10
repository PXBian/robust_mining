#!/bin/bash
module load pandas
make all
# g++ -O3 -std=c++11 rebuttal_resi.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o reb_resi
g++ -O3 -std=c++11 rebuttal_freq.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o reb_freq

# ## ./reb_freq concentrate_file tau k origin_file K(for top-K frequent) g(number of ground truth clusters)

# ./reb_freq INFL_con.str 10 10 INFL.str 5   5 INFL_label.csv 
# ./reb_freq INFL_con.str 10 10 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 10 10 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 20 20 INFL.str 5   5 INFL_label.csv 
# ./reb_freq INFL_con.str 20 20 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 20 20 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 30 30 INFL.str 5   5 INFL_label.csv 
# ./reb_freq INFL_con.str 30 30 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 30 30 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 40 40 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 40 40 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 50 50 INFL.str 5   5 INFL_label.csv 
# ./reb_freq INFL_con.str 50 50 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 60 60 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 60 60 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 70 70 INFL.str 5   5 INFL_label.csv 
# ./reb_freq INFL_con.str 70 70 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 70 70 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 80 80 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 80 80 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 90 90 INFL.str 5   5 INFL_label.csv 
# ./reb_freq INFL_con.str 90 90 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 90 90 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 50 50 INFL.str 5   5 INFL_label.csv 
# ./reb_freq INFL_con.str 50 50 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 50 50 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 100 100 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 100 100 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 150 150 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 150 150 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 200 200 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 200 200 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 250 250 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 250 250 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 300 300 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 300 300 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 350 350 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 350 350 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 400 400 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 400 400 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 450 450 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 450 450 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 500 500 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 500 500 INFL.str 100 5 INFL_label.csv


# ./reb_freq INFL_con.str 550 550 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 550 550 INFL.str 100 5 INFL_label.csv


# ./reb_freq INFL_con.str 600 600 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 600 600 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 650 650 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 650 650 INFL.str 100 5 INFL_label.csv

# ./reb_freq INFL_con.str 700 700 INFL.str 5   5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 10  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 15  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 20  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 25  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 30  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 35  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 40  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 45  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 50  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 55  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 60  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 65  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 70  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 75  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 80  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 85  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 90  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 95  5 INFL_label.csv
# ./reb_freq INFL_con.str 700 700 INFL.str 100 5 INFL_label.csv



# ./reb_freq EBOL_con.str 100 100 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 100 100 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 200 200 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 200 200 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 300 300 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 300 300 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 400 400 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 400 400 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 500 500 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 500 500 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 600 600 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 600 600 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 700 700 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 700 700 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 800 800 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 800 800 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 900 900 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 900 900 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1000 1000 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 1500 1500 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2000 2000 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 2500 2500 EBOL.str 1000 5 EBOL_label.csv

# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 10   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 20   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 30   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 40   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 50   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 60   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 70   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 80   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 90   5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 100  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 150  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 200  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 250  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 300  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 350  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 400  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 450  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 500  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 550  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 600  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 650  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 700  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 750  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 800  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 850  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 900  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 950  5 EBOL_label.csv
# ./reb_freq EBOL_con.str 3000 3000 EBOL.str 1000 5 EBOL_label.csv





./reb_freq COR_con.str 100 100 COR.str 10   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 20   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 30   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 40   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 50   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 60   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 70   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 80   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 90   5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 100  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 150  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 200  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 250  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 300  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 350  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 400  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 450  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 500  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 550  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 600  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 650  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 700  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 750  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 800  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 850  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 900  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 950  5 COR_label.csv
./reb_freq COR_con.str 100 100 COR.str 1000 5 COR_label.csv

./reb_freq COR_con.str 200 200 COR.str 10   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 20   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 30   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 40   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 50   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 60   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 70   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 80   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 90   5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 100  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 150  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 200  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 250  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 300  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 350  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 400  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 450  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 500  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 550  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 600  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 650  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 700  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 750  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 800  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 850  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 900  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 950  5 COR_label.csv
./reb_freq COR_con.str 200 200 COR.str 1000 5 COR_label.csv

./reb_freq COR_con.str 300 300 COR.str 10   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 20   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 30   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 40   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 50   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 60   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 70   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 80   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 90   5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 100  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 150  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 200  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 250  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 300  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 350  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 400  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 450  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 500  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 550  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 600  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 650  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 700  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 750  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 800  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 850  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 900  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 950  5 COR_label.csv
./reb_freq COR_con.str 300 300 COR.str 1000 5 COR_label.csv

./reb_freq COR_con.str 400 400 COR.str 10   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 20   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 30   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 40   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 50   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 60   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 70   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 80   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 90   5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 100  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 150  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 200  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 250  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 300  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 350  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 400  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 450  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 500  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 550  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 600  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 650  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 700  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 750  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 800  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 850  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 900  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 950  5 COR_label.csv
./reb_freq COR_con.str 400 400 COR.str 1000 5 COR_label.csv

./reb_freq COR_con.str 500 500 COR.str 10   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 20   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 30   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 40   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 50   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 60   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 70   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 80   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 90   5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 100  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 150  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 200  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 250  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 300  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 350  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 400  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 450  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 500  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 550  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 600  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 650  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 700  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 750  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 800  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 850  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 900  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 950  5 COR_label.csv
./reb_freq COR_con.str 500 500 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 600 600 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 600 600 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 700 700 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 700 700 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 800 800 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 800 800 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 900 900 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 900 900 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 1000 1000 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 1000 1000 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 1500 1500 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 1500 1500 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 2000 2000 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 2000 2000 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 2500 2500 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 2500 2500 COR.str 1000 5 COR_label.csv

# ./reb_freq COR_con.str 3000 3000 COR.str 10   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 20   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 30   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 40   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 50   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 60   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 70   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 80   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 90   5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 100  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 150  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 200  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 250  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 300  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 350  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 400  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 450  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 500  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 550  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 600  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 650  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 700  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 750  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 800  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 850  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 900  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 950  5 COR_label.csv
# ./reb_freq COR_con.str 3000 3000 COR.str 1000 5 COR_label.csv

