#!/bin/bash
make all
g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case


(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 10     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_10.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 100    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_100.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 1000   /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_1000.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 10000 10000  /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_10000_10000.txt

(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 10      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_10.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 100     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_100.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 1000    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_1000.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 1000 10000   /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_1000_10000.txt 

(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 10       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_10.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 100      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_100.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 1000     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_1000.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100 10000    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt)   &> peak_ram/casestudy_16_100_10000.txt 


(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 10000 10     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_10000_10.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 10000 100    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_10000_100.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 10000 1000   /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_10000_1000.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 10000 10000  /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_10000_10000.txt

(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 1000 10      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_1000_10.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 1000 100     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_1000_100.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 1000 1000    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_1000_1000.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 1000 10000   /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_1000_10000.txt 

(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 100 10       /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_100_10.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 100 100      /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_100_100.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 100 1000     /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_100_1000.txt 
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128.txt 100 10000    /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_128_1.txt)   &> peak_ram/casestudy_128_100_10000.txt 
