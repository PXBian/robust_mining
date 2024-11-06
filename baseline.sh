#!/bin/bash

mkdir peak_ram
rm runtime_details.csv
make all
g++ baseline.cc -o baseline
rm output/*

# # ./baseline <text_file> <k> <t> <output_file>
# (/usr/bin/time -v ./baseline data/ecoli10000  5   50 bl_output)    &> peak_ram/bl_base_ecoli10000_50_5.txt
# (/usr/bin/time -v ./baseline data/ecoli10000  10  50 bl_output)    &> peak_ram/bl_base_ecoli10000_50_10.txt
# (/usr/bin/time -v ./baseline data/ecoli10000  20  50 bl_output)    &> peak_ram/bl_base_ecoli10000_50_20.txt
# (/usr/bin/time -v ./baseline data/ecoli10000  50  50 bl_output)    &> peak_ram/bl_base_ecoli10000_50_50.txt
# (/usr/bin/time -v ./baseline data/ecoli10000  100 50 bl_output)    &> peak_ram/bl_base_ecoli10000_50_100.txt

# (/usr/bin/time -v ./baseline data/ecoli10000  10 5   bl_output)    &> peak_ram/bl_base_ecoli10000_5_10.txt
# (/usr/bin/time -v ./baseline data/ecoli10000  10 10  bl_output)    &> peak_ram/bl_base_ecoli10000_10_10.txt
# (/usr/bin/time -v ./baseline data/ecoli10000  10 20  bl_output)    &> peak_ram/bl_base_ecoli10000_20_10.txt
# (/usr/bin/time -v ./baseline data/ecoli10000  10 50  bl_output)    &> peak_ram/bl_base_ecoli10000_50_10.txt
# (/usr/bin/time -v ./baseline data/ecoli10000  10 100 bl_output)    &> peak_ram/bl_base_ecoli10000_100_10.txt


# (/usr/bin/time -v ./main data/ecoli10000  50 5   )    &> peak_ram/bl_main_ecoli10000_50_5.txt
# (/usr/bin/time -v ./main data/ecoli10000  50 10  )    &> peak_ram/bl_main_ecoli10000_50_10.txt
# (/usr/bin/time -v ./main data/ecoli10000  50 20  )    &> peak_ram/bl_main_ecoli10000_50_20.txt
# (/usr/bin/time -v ./main data/ecoli10000  50 50  )    &> peak_ram/bl_main_ecoli10000_50_50.txt
# (/usr/bin/time -v ./main data/ecoli10000  50 100 )    &> peak_ram/bl_main_ecoli10000_50_100.txt

# (/usr/bin/time -v ./main data/ecoli10000  5   10 )    &> peak_ram/bl_main_ecoli10000_5_10.txt
# (/usr/bin/time -v ./main data/ecoli10000  10  10 )    &> peak_ram/bl_main_ecoli10000_10_10.txt
# (/usr/bin/time -v ./main data/ecoli10000  20  10 )    &> peak_ram/bl_main_ecoli10000_20_10.txt
# (/usr/bin/time -v ./main data/ecoli10000  50  10 )    &> peak_ram/bl_main_ecoli10000_50_10.txt
# (/usr/bin/time -v ./main data/ecoli10000  100 10 )    &> peak_ram/bl_main_ecoli10000_100_10.txt


(/usr/bin/time -v ./main data/ecoli1000   50 10 )    &> peak_ram/bl_main_ecoli1000_50_10.txt
(/usr/bin/time -v ./main data/ecoli2000   50 10 )    &> peak_ram/bl_main_ecoli2000_50_10.txt
(/usr/bin/time -v ./main data/ecoli5000   50 10 )    &> peak_ram/bl_main_ecoli5000_50_10.txt
(/usr/bin/time -v ./main data/ecoli10000  50 10 )    &> peak_ram/bl_main_ecoli10000_50_10.txt
(/usr/bin/time -v ./main data/ecoli20000  50 10 )    &> peak_ram/bl_main_ecoli20000_50_10.txt
(/usr/bin/time -v ./main data/ecoli50000  50 10 )    &> peak_ram/bl_main_ecoli50000_50_10.txt
(/usr/bin/time -v ./main data/ecoli100000 50 10 )    &> peak_ram/bl_main_ecoli100000_50_10.txt


(/usr/bin/time -v ./baseline data/ecoli1000   10 50 bl_output)    &> peak_ram/bl_base_ecoli1000_50_10.txt
(/usr/bin/time -v ./baseline data/ecoli2000   10 50 bl_output)    &> peak_ram/bl_base_ecoli2000_50_10.txt
(/usr/bin/time -v ./baseline data/ecoli5000   10 50 bl_output)    &> peak_ram/bl_base_ecoli5000_50_10.txt
(/usr/bin/time -v ./baseline data/ecoli10000  10 50 bl_output)    &> peak_ram/bl_base_ecoli10000_50_10.txt
(/usr/bin/time -v ./baseline data/ecoli20000  10 50 bl_output)    &> peak_ram/bl_base_ecoli20000_50_10.txt
(/usr/bin/time -v ./baseline data/ecoli50000  10 50 bl_output)    &> peak_ram/bl_base_ecoli50000_50_10.txt
(/usr/bin/time -v ./baseline data/ecoli100000 10 50 bl_output)    &> peak_ram/bl_base_ecoli100000_50_10.txt



# # ## change n
# (/usr/bin/time -v ./main data/dna.200MB_25MB   10000 100)    &> peak_ram/ex_dna200_25MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_50MB   10000 100)    &> peak_ram/ex_dna200_50MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_75MB   10000 100)    &> peak_ram/ex_dna200_75MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_100MB  10000 100)    &> peak_ram/ex_dna200_100MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_125MB  10000 100)    &> peak_ram/ex_dna200_125MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_150MB  10000 100)    &> peak_ram/ex_dna200_150MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_175MB  10000 100)    &> peak_ram/ex_dna200_175MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB        10000 100)    &> peak_ram/ex_dna200_10000_100.txt



# ## Larger data
# (/usr/bin/time -v ./baseline data/ecoli100000  5   50 bl_output)    &> peak_ram/bl_base_ecoli100000_50_5.txt
# (/usr/bin/time -v ./baseline data/ecoli100000  10  50 bl_output)    &> peak_ram/bl_base_ecoli100000_50_10.txt
# (/usr/bin/time -v ./baseline data/ecoli100000  20  50 bl_output)    &> peak_ram/bl_base_ecoli100000_50_20.txt
# (/usr/bin/time -v ./baseline data/ecoli100000  50  50 bl_output)    &> peak_ram/bl_base_ecoli100000_50_50.txt
# (/usr/bin/time -v ./baseline data/ecoli100000  100 50 bl_output)    &> peak_ram/bl_base_ecoli100000_50_100.txt

# (/usr/bin/time -v ./baseline data/ecoli100000  10 5   bl_output)    &> peak_ram/bl_base_ecoli100000_5_10.txt
# (/usr/bin/time -v ./baseline data/ecoli100000  10 10  bl_output)    &> peak_ram/bl_base_ecoli100000_10_10.txt
# (/usr/bin/time -v ./baseline data/ecoli100000  10 20  bl_output)    &> peak_ram/bl_base_ecoli100000_20_10.txt
# (/usr/bin/time -v ./baseline data/ecoli100000  10 50  bl_output)    &> peak_ram/bl_base_ecoli100000_50_10.txt
# (/usr/bin/time -v ./baseline data/ecoli100000  10 100 bl_output)    &> peak_ram/bl_base_ecoli100000_100_10.txt


# (/usr/bin/time -v ./main data/ecoli100000  50 5   )    &> peak_ram/bl_main_ecoli100000_50_5.txt
# (/usr/bin/time -v ./main data/ecoli100000  50 10  )    &> peak_ram/bl_main_ecoli100000_50_10.txt
# (/usr/bin/time -v ./main data/ecoli100000  50 20  )    &> peak_ram/bl_main_ecoli100000_50_20.txt
# (/usr/bin/time -v ./main data/ecoli100000  50 50  )    &> peak_ram/bl_main_ecoli100000_50_50.txt
# (/usr/bin/time -v ./main data/ecoli100000  50 100 )    &> peak_ram/bl_main_ecoli100000_50_100.txt

# (/usr/bin/time -v ./main data/ecoli100000  5   10 )    &> peak_ram/bl_main_ecoli100000_5_10.txt
# (/usr/bin/time -v ./main data/ecoli100000  10  10 )    &> peak_ram/bl_main_ecoli100000_10_10.txt
# (/usr/bin/time -v ./main data/ecoli100000  20  10 )    &> peak_ram/bl_main_ecoli100000_20_10.txt
# (/usr/bin/time -v ./main data/ecoli100000  50  10 )    &> peak_ram/bl_main_ecoli100000_50_10.txt
# (/usr/bin/time -v ./main data/ecoli100000  100 10 )    &> peak_ram/bl_main_ecoli100000_100_10.txt

