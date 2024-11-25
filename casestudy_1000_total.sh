#!/bin/bash
make all
g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case
mkdir output
# wget "https://www.dropbox.com/scl/fi/3hnd8dxu4ilu1bnfwwwnp/chr19_pengxin_1000.txt.gz?rlkey=061f4x0nm1lt9av3xc3h6j6tz&st=22eyyi5j&dl=1" -O chr19_pengxin_1000.txt.gz
# gunzip -c chr19_pengxin_1000.txt.gz > data/chr19_pengxin_1000.txt

(
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 500 5      data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_500_5.txt     &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 500 10     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_500_10.txt    &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 500 20     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_500_20.txt    &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 500 50     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_500_50.txt    &

# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 1000 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_1000_5.txt    &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 1000 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_1000_10.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 1000 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_1000_20.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 1000 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_1000_50.txt   &

# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 2500 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_2500_5.txt    &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 2500 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_2500_10.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 2500 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_2500_20.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 2500 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_2500_50.txt   &

# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 5000 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_5000_5.txt    &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 5000 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_5000_10.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 5000 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_5000_20.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 5000 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_5000_50.txt   &

# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 7500 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_7500_5.txt    &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 7500 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_7500_10.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 7500 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_7500_20.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 7500 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_7500_50.txt   &

# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 10000 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_10000_5.txt    &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 10000 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_10000_10.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 10000 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_10000_20.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 10000 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_10000_50.txt   &

# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 15000 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_15000_5.txt    &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 15000 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_15000_10.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 15000 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_15000_20.txt   &
# (/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 15000 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_15000_50.txt   &

(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 20000 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_20000_5.txt    &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 20000 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_20000_10.txt   &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 20000 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_20000_20.txt   &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 20000 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_20000_50.txt   &

(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 30000 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_30000_5.txt    &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 30000 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_30000_10.txt   &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 30000 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_30000_20.txt   &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 30000 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_30000_50.txt   &

(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 40000 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_40000_5.txt    &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 40000 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_40000_10.txt   &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 40000 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_40000_20.txt   &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 40000 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_40000_50.txt   &

(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 50000 5     data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_50000_5.txt    &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 50000 10    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_50000_10.txt   &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 50000 20    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_50000_20.txt   &
(/usr/bin/time -v ./case data/chr19_pengxin_1000.txt 50000 50    data/chr19_pengxin_1000_1.txt)   &> peak_ram/casestudy_1000_50000_50.txt   &

)


