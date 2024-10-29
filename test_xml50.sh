#!/bin/bash

# mkdir peak_ram
# # rm runtime_details.csv
# gunzip *.gz

# (/usr/bin/time -v ./main 16_1.txt 1000 10000)     &> peak_ram/case_main_16_1_1000_10000.txt
# ./main dna.200MB 1000 10000


# (/usr/bin/time -v ./main dblp.xml.50MB 100 100)     &> peak_ram/mem_xml50_100_100.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 100 1000)    &> peak_ram/mem_xml50_100_1000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 100 10000)   &> peak_ram/mem_xml50_100_10000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 1000 100)    &> peak_ram/mem_xml50_1000_100.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 1000 1000)   &> peak_ram/mem_xml50_1000_1000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 1000 10000)  &> peak_ram/mem_xml50_1000_10000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 10000 100)   &> peak_ram/mem_xml50_10000_100.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 10000 1000)  &> peak_ram/mem_xml50_10000_1000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 10000 10000) &> peak_ram/mem_xml50_10000_10000.txt



make all
# g++ case_study.cpp suffixtree.hpp -o case
g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case

# (/usr/bin/time -v ./main dna.50MB  1000 100)      &> peak_ram/mem_dna50_1000_100.txt
# (/usr/bin/time -v ./main dna.50MB  1000 1000)     &> peak_ram/mem_dna50_1000_1000.txt
# (/usr/bin/time -v ./main data/dna.50MB  1000 10000)    &> peak_ram/mem_dna50_1000_10000.txt
# (/usr/bin/time -v ./main dna.100MB 1000 100)      &> peak_ram/mem_dna100_1000_100.txt
# (/usr/bin/time -v ./main dna.100MB 1000 1000)     &> peak_ram/mem_dna100_1000_1000.txt
# (/usr/bin/time -v ./main data/dna.100MB 1000 10000)    &> peak_ram/mem_dna100_1000_10000.txt
# (/usr/bin/time -v ./main dna.200MB 1000 100)      &> peak_ram/mem_dna200_1000_100.txt
# (/usr/bin/time -v ./main dna.200MB 1000 1000)     &> peak_ram/mem_dna200_1000_1000.txt
# (/usr/bin/time -v ./main data/dna.200MB 1000 10000)    &> peak_ram/mem_dna200_1000_10000.txt

# (/usr/bin/time -v ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_16.txt 100000 1000 /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_1M.txt)     &> peak_ram/casestudy_16_check_N.txt
# (/usr/bin/time -v ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_32.txt 100000 1000 /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_1M.txt)     &> peak_ram/casestudy_32_check_N.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16.txt 100000 1000 /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_1M.txt)     &> peak_ram/casestudy_16_check_N_remove.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_32.txt 100000 1000 /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_1M.txt)     &> peak_ram/casestudy_32_check_N_remove.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_16_1.txt 100000 1000 /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_1M.txt)     &> peak_ram/casestudy_16_1_check_N_remove.txt
(/usr/bin/time -v ./case /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_pengxin_32_1.txt 100000 1000 /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_1M.txt)     &> peak_ram/casestudy_32_1_check_N_remove.txt
# (/usr/bin/time -v ./case /scratch/prj/proj_loukides/github_useful_strings/useful_strings/chr19_pengxin_64.txt 100000 1000 /scratch/prj/proj_loukides/pengxin/robust_mining/chr19_1M.txt)     &> peak_ram/casestudy_64_check_N.txt


# (/usr/bin/time -v ./case chr19_pengxin_16.txt 10000 100 chr19_1M.txt)     &> peak_ram/casestudy_1_1M_10000_100.txt
# (/usr/bin/time -v ./case chr19_pengxin_32.txt 10000 100 chr19_1M.txt)     &> peak_ram/case_study_1M_10000_100.txt

# (/usr/bin/time -v ./main chr19_pengxin_16_1.txt 10000 10000)     &> peak_ram/case_main_16_1_10000_10000.txt


# (/usr/bin/time -v ./main dna.50MB 100 100)      &> peak_ram/mem_dna50_100_100.txt
# (/usr/bin/time -v ./main dna.50MB 100 1000)     &> peak_ram/mem_dna50_100_1000.txt
# (/usr/bin/time -v ./main dna.50MB 100 10000)    &> peak_ram/mem_dna50_100_10000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 100)     &> peak_ram/mem_dna50_1000_100.txt
# (/usr/bin/time -v ./main dna.50MB 1000 1000)    &> peak_ram/mem_dna50_1000_1000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 10000)   &> peak_ram/mem_dna50_1000_10000.txt
# (/usr/bin/time -v ./main dna.50MB 10000 100)    &> peak_ram/mem_dna50_10000_100.txt
# (/usr/bin/time -v ./main dna.50MB 10000 1000)   &> peak_ram/mem_dna50_10000_1000.txt
# (/usr/bin/time -v ./main dna.50MB 10000 10000)  &> peak_ram/mem_dna50_10000_10000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 15000)      &> peak_ram/mem_dna50_100_100.txt
# (/usr/bin/time -v ./main dna.50MB 1000 20000)   &> peak_ram/mem_dna50_1000_20000.txt
# (/usr/bin/time -v ./main dna.50MB 1009 25000)    &> peak_ram/mem_dna50_100_10000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 30000)   &> peak_ram/mem_dna50_1000_30000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 35000)    &> peak_ram/mem_dna50_1000_1000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 40000)   &> peak_ram/mem_dna50_1000_40000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 45000)    &> peak_ram/mem_dna50_10000_100.txt
# (/usr/bin/time -v ./main dna.50MB 1000 50000)   &> peak_ram/mem_dna50_1000_50000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 55000)   &> peak_ram/mem_dna50_1000_55000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 60000)   &> peak_ram/mem_dna50_1000_60000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 70000)   &> peak_ram/mem_dna50_1000_70000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 80000)   &> peak_ram/mem_dna50_1000_80000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 90000)   &> peak_ram/mem_dna50_1000_90000.txt
# (/usr/bin/time -v ./main dna.50MB 1000 100000)  &> peak_ram/mem_dna50_1000_100000.txt



# (/usr/bin/time -v ./main dna.100MB 100 100)      &> peak_ram/mem_dna100_100_100.txt
# (/usr/bin/time -v ./main dna.100MB 100 1000)     &> peak_ram/mem_dna100_100_1000.txt
# (/usr/bin/time -v ./main dna.100MB 100 10000)    &> peak_ram/mem_dna100_100_10000.txt
# (/usr/bin/time -v ./main dna.100MB 1000 100)     &> peak_ram/mem_dna100_1000_100.txt
# (/usr/bin/time -v ./main dna.100MB 1000 1000)    &> peak_ram/mem_dna100_1000_1000.txt
# (/usr/bin/time -v ./main dna.100MB 1000 10000)   &> peak_ram/mem_dna100_1000_10000.txt
# (/usr/bin/time -v ./main dna.100MB 10000 100)    &> peak_ram/mem_dna100_10000_100.txt
# (/usr/bin/time -v ./main dna.100MB 10000 1000)   &> peak_ram/mem_dna100_10000_1000.txt
# (/usr/bin/time -v ./main dna.100MB 10000 10000)  &> peak_ram/mem_dna100_10000_10000.txt

# (/usr/bin/time -v ./main dna.200MB 100 100)      &> peak_ram/mem_dna200_100_100.txt
# (/usr/bin/time -v ./main dna.200MB 100 1000)     &> peak_ram/mem_dna200_100_1000.txt
# (/usr/bin/time -v ./main dna.200MB 100 10000)    &> peak_ram/mem_dna200_100_10000.txt
# (/usr/bin/time -v ./main dna.200MB 1000 100)     &> peak_ram/mem_dna200_1000_100.txt
# (/usr/bin/time -v ./main dna.200MB 1000 1000)    &> peak_ram/mem_dna200_1000_1000.txt
# (/usr/bin/time -v ./main dna.200MB 1000 10000)   &> peak_ram/mem_dna200_1000_10000.txt
# (/usr/bin/time -v ./main dna.200MB 10000 100)    &> peak_ram/mem_dna200_10000_100.txt
# (/usr/bin/time -v ./main dna.200MB 10000 1000)   &> peak_ram/mem_dna200_10000_1000.txt
# (/usr/bin/time -v ./main dna.200MB 10000 10000)  &> peak_ram/mem_dna200_10000_10000.txt