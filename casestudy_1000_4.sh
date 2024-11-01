#!/bin/bash
# make all
# g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case

# mkdir output

# wget "https://www.dropbox.com/scl/fi/3hnd8dxu4ilu1bnfwwwnp/chr19_pengxin_1000.txt.gz?rlkey=061f4x0nm1lt9av3xc3h6j6tz&st=22eyyi5j&dl=1" -O chr19_pengxin_1000.txt.gz
# gunzip -c chr19_pengxin_1000.txt.gz > data/chr19_pengxin_1000.txt


# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 10000 10     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_10000_10.txt
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 10000 100    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_10000_100.txt
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 10000 1000   data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_10000_1000.txt
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 10000 10000  data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_10000_10000.txt

# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 1000 10      data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_1000_10.txt 
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 1000 100     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_1000_100.txt 
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 1000 1000    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_1000_1000.txt 
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 1000 10000   data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_1000_10000.txt 

