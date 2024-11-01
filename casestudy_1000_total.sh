#!/bin/bash
make all
g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case
mkdir output
wget "https://www.dropbox.com/scl/fi/3hnd8dxu4ilu1bnfwwwnp/chr19_pengxin_1000.txt.gz?rlkey=061f4x0nm1lt9av3xc3h6j6tz&st=22eyyi5j&dl=1" -O chr19_pengxin_1000.txt.gz
gunzip -c chr19_pengxin_1000.txt.gz > data/chr19_pengxin_1000.txt

(
bash casestudy_1000_1.sh  &
bash casestudy_1000_2.sh  &
bash casestudy_1000_3.sh  &
bash casestudy_1000_4.sh  &
bash casestudy_1000_5.sh  &
bash casestudy_1000_6.sh  &
bash casestudy_1000_7.sh  &
bash casestudy_1000_8.sh  &
)

