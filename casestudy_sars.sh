#!/bin/bash

make all
g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case
mkdir output
mkdir peak_ram

(
    (/usr/bin/time -v ./case data/sars_1435K.fna 500   5    data/sars_1.txt)   &> peak_ram/casestudy_sars_500_5.txt     &
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  5    data/sars_2.txt)   &> peak_ram/casestudy_sars_1000_5.txt    &
    (/usr/bin/time -v ./case data/sars_1435K.fna 10000 5    data/sars_3.txt)   &> peak_ram/casestudy_sars_10000_5.txt   &

    (/usr/bin/time -v ./case data/sars_1435K.fna 500   50   data/sars_4.txt)   &> peak_ram/casestudy_sars_500_50.txt    &
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  50   data/sars_5.txt)   &> peak_ram/casestudy_sars_1000_50.txt   &
    (/usr/bin/time -v ./case data/sars_1435K.fna 10000 50   data/sars_6.txt)   &> peak_ram/casestudy_sars_10000_50.txt  &

)