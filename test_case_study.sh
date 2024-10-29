#!/bin/bash
make all
g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case


(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100000 20    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100000_20.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100000 40    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100000_40.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100000 60    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100000_60.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100000 80    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100000_80.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100000 100   /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100000_100.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100000 1000  /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100000_1000.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100000 10000 /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100000_10000.txt

(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 20     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_20.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 40     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_40.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 60     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_60.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 80     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_80.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 100    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_100.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 1000   /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_1000.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 10000  /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_10000.txt

(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 20      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_20.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 40      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_40.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 60      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_60.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 80      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_80.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 100     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_100.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 1000    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_1000.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 10000   /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_10000.txt 


# (/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 3       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)    &> peak_ram/casestudy_16_100_3.txt 
# (/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 5       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)    &> peak_ram/casestudy_16_100_5.txt 
# (/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 10       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_10.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 20       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_20.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 40       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_40.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 60       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_60.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 80       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_80.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 100      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_100.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 1000     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_1000.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 10000    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_10000.txt 




# ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16.txt 100000 400 /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16_1.txt
# ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16.txt 100000 500 /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16_1.txt 
# ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16.txt 100000 600 /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16_1.txt 
# ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16.txt 100000 700 /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16_1.txt 
# ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16.txt 100000 800 /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16_1.txt 
# ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16.txt 100000 900 /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16_1.txt 

