#!/bin/bash

make all
g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case
mkdir output
mkdir peak_ram

(
    (/usr/bin/time -v ./case /scratch_tmp/prj/proj_loukides/ling/kkp/examples/sars_cleaned/sars_0-1000K_top1.fna 500   5    data/sars_1.txt)   &> peak_ram/casestudy_sars_500_5.txt      &
    # (/usr/bin/time -v ./case /scratch_tmp/prj/proj_loukides/ling/kkp/examples/sars_cleaned/sars_0-1000K_top1.fna 1000  5    data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_5.txt     &
    # (/usr/bin/time -v ./case /scratch_tmp/prj/proj_loukides/ling/kkp/examples/sars_cleaned/sars_0-1000K_top1.fna 10000 5    data/sars_1.txt)   &> peak_ram/casestudy_sars_10000_5.txt    &

    # (/usr/bin/time -v ./case /scratch_tmp/prj/proj_loukides/ling/kkp/examples/sars_cleaned/sars_0-1000K_top1.fna 500   50   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_50.txt     &
    # (/usr/bin/time -v ./case /scratch_tmp/prj/proj_loukides/ling/kkp/examples/sars_cleaned/sars_0-1000K_top1.fna 1000  50   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_50.txt    &
    # (/usr/bin/time -v ./case /scratch_tmp/prj/proj_loukides/ling/kkp/examples/sars_cleaned/sars_0-1000K_top1.fna 10000 50   data/sars_1.txt)   &> peak_ram/casestudy_sars_10000_50.txt   &

)