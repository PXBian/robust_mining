#!/bin/bash

mkdir peak_ram
mkdir output
# rm output/*
# g++ -O3 -DNDEBUG -I ~/include -L ~/lib runs.hpp intervaltree.hpp main_ESA.cpp -o esa -lsdsl -ldivsufsort -ldivsufsort64
g++ -O3 -DNDEBUG -I ./libsdsl/include/ -L ./libsdsl/lib/ runs.hpp intervaltree.hpp main_ESA.cpp -o esa -lsdsl -ldivsufsort -ldivsufsort64


# # change tau
# (/usr/bin/time -v ./esa data/dna.200MB 10       100)   &> peak_ram/esa_dna200_10_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB 100      100)   &> peak_ram/esa_dna200_100_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB 1000     100)   &> peak_ram/esa_dna200_1000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB 10000    100)   &> peak_ram/esa_dna200_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB 100000   100)   &> peak_ram/esa_dna200_100000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB 1000000  100)   &> peak_ram/esa_dna200_1000000_100.txt

# # change k
# (/usr/bin/time -v ./esa data/dna.200MB 10000 10     )    &> peak_ram/esa_dna200_10000_10.txt
# (/usr/bin/time -v ./esa data/dna.200MB 10000 100    )    &> peak_ram/esa_dna200_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB 10000 1000   )    &> peak_ram/esa_dna200_10000_1000.txt
# (/usr/bin/time -v ./esa data/dna.200MB 10000 10000  )    &> peak_ram/esa_dna200_10000_10000.txt
# (/usr/bin/time -v ./esa data/dna.200MB 10000 100000 )    &> peak_ram/esa_dna200_10000_100000.txt
# (/usr/bin/time -v ./esa data/dna.200MB 10000 1000000)    &> peak_ram/esa_dna200_10000_1000000.txt



# ## change tau
# (/usr/bin/time -v ./esa data/proteins.200MB 10       100)   &> peak_ram/esa_proteins200_10_100.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 100      100)   &> peak_ram/esa_proteins200_100_100.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 1000     100)   &> peak_ram/esa_proteins200_1000_100.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 10000    100)   &> peak_ram/esa_proteins200_10000_100.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 100000   100)   &> peak_ram/esa_proteins200_100000_100.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 1000000  100)   &> peak_ram/esa_proteins200_1000000_100.txt

# # change k
# (/usr/bin/time -v ./esa data/proteins.200MB 10000 10     )    &> peak_ram/esa_proteins200_10000_10.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 10000 100    )    &> peak_ram/esa_proteins200_10000_100.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 10000 1000   )    &> peak_ram/esa_proteins200_10000_1000.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 10000 10000  )    &> peak_ram/esa_proteins200_10000_10000.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 10000 100000 )    &> peak_ram/esa_proteins200_10000_100000.txt
# (/usr/bin/time -v ./esa data/proteins.200MB 10000 1000000)    &> peak_ram/esa_proteins200_10000_1000000.txt



# # change tau
# (/usr/bin/time -v ./esa data/english.200MB 10       100)   &> peak_ram/esa_english200_10_100.txt
# (/usr/bin/time -v ./esa data/english.200MB 100      100)   &> peak_ram/esa_english200_100_100.txt
# (/usr/bin/time -v ./esa data/english.200MB 1000     100)   &> peak_ram/esa_english200_1000_100.txt
# (/usr/bin/time -v ./esa data/english.200MB 10000    100)   &> peak_ram/esa_english200_10000_100.txt
# (/usr/bin/time -v ./esa data/english.200MB 100000   100)   &> peak_ram/esa_english200_100000_100.txt
# (/usr/bin/time -v ./esa data/english.200MB 1000000  100)   &> peak_ram/esa_english200_1000000_100.txt

# # change k
# (/usr/bin/time -v ./esa data/english.200MB 10000 10     )    &> peak_ram/esa_english200_10000_10.txt
# (/usr/bin/time -v ./esa data/english.200MB 10000 100    )    &> peak_ram/esa_english200_10000_100.txt
# (/usr/bin/time -v ./esa data/english.200MB 10000 1000   )    &> peak_ram/esa_english200_10000_1000.txt
# (/usr/bin/time -v ./esa data/english.200MB 10000 10000  )    &> peak_ram/esa_english200_10000_10000.txt
# (/usr/bin/time -v ./esa data/english.200MB 10000 100000 )    &> peak_ram/esa_english200_10000_100000.txt
# (/usr/bin/time -v ./esa data/english.200MB 10000 1000000)    &> peak_ram/esa_english200_10000_1000000.txt



# # change tau
# (/usr/bin/time -v ./esa data/sources.200MB 10       100)   &> peak_ram/esa_sources200_10_100.txt
# (/usr/bin/time -v ./esa data/sources.200MB 100      100)   &> peak_ram/esa_sources200_100_100.txt
# (/usr/bin/time -v ./esa data/sources.200MB 1000     100)   &> peak_ram/esa_sources200_1000_100.txt
# (/usr/bin/time -v ./esa data/sources.200MB 10000    100)   &> peak_ram/esa_sources200_10000_100.txt
# (/usr/bin/time -v ./esa data/sources.200MB 100000   100)   &> peak_ram/esa_sources200_100000_100.txt
# (/usr/bin/time -v ./esa data/sources.200MB 1000000  100)   &> peak_ram/esa_sources200_1000000_100.txt

# # change k
# (/usr/bin/time -v ./esa data/sources.200MB 10000 10      )    &> peak_ram/esa_sources200_10000_10.txt
# (/usr/bin/time -v ./esa data/sources.200MB 10000 100     )    &> peak_ram/esa_sources200_10000_100.txt
# (/usr/bin/time -v ./esa data/sources.200MB 10000 1000    )    &> peak_ram/esa_sources200_10000_1000.txt
# (/usr/bin/time -v ./esa data/sources.200MB 10000 10000   )    &> peak_ram/esa_sources200_10000_10000.txt
# (/usr/bin/time -v ./esa data/sources.200MB 10000 100000  )    &> peak_ram/esa_sources200_10000_100000.txt
# (/usr/bin/time -v ./esa data/sources.200MB 10000 1000000 )    &> peak_ram/esa_sources200_10000_1000000.txt



# # change tau
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 10       100)   &> peak_ram/esa_xml200_10_100.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 100      100)   &> peak_ram/esa_xml200_100_100.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 1000     100)   &> peak_ram/esa_xml200_1000_100.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 10000    100)   &> peak_ram/esa_xml200_10000_100.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 100000   100)   &> peak_ram/esa_xml200_100000_100.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 1000000  100)   &> peak_ram/esa_xml200_1000000_100.txt

# # change k
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 10000 10      )    &> peak_ram/esa_xml200_10000_10.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 10000 100     )    &> peak_ram/esa_xml200_10000_100.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 10000 1000    )    &> peak_ram/esa_xml200_10000_1000.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 10000 10000   )    &> peak_ram/esa_xml200_10000_10000.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 10000 100000  )    &> peak_ram/esa_xml200_10000_100000.txt
# (/usr/bin/time -v ./esa data/dblp.xml.200MB 10000 1000000 )    &> peak_ram/esa_xml200_10000_1000000.txt



# ## change n
# (/usr/bin/time -v ./esa data/dna.200MB_25MB   10000 100)    &> peak_ram/esa_dna200_25MB_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB_50MB   10000 100)    &> peak_ram/esa_dna200_50MB_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB_75MB   10000 100)    &> peak_ram/esa_dna200_75MB_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB_100MB  10000 100)    &> peak_ram/esa_dna200_100MB_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB_125MB  10000 100)    &> peak_ram/esa_dna200_125MB_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB_150MB  10000 100)    &> peak_ram/esa_dna200_150MB_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB_175MB  10000 100)    &> peak_ram/esa_dna200_175MB_10000_100.txt
# (/usr/bin/time -v ./esa data/dna.200MB        10000 100)    &> peak_ram/esa_dna200_10000_100.txt



## change tau
(/usr/bin/time -v ./esa data/dna.200MB      5        100)   &> peak_ram/esa_dna200_5_100.txt
(/usr/bin/time -v ./esa data/dna.200MB      50       100)   &> peak_ram/esa_dna200_50_100.txt
(/usr/bin/time -v ./esa data/dna.200MB      500      100)   &> peak_ram/esa_dna200_500_100.txt
(/usr/bin/time -v ./esa data/dna.200MB      5000     100)   &> peak_ram/esa_dna200_5000_100.txt
(/usr/bin/time -v ./esa data/dna.200MB      50000    100)   &> peak_ram/esa_dna200_50000_100.txt

## change tau
(/usr/bin/time -v ./esa data/proteins.200MB 5        100)   &> peak_ram/esa_proteins200_5_100.txt
(/usr/bin/time -v ./esa data/proteins.200MB 50       100)   &> peak_ram/esa_proteins200_50_100.txt
(/usr/bin/time -v ./esa data/proteins.200MB 500      100)   &> peak_ram/esa_proteins200_500_100.txt
(/usr/bin/time -v ./esa data/proteins.200MB 5000     100)   &> peak_ram/esa_proteins200_5000_100.txt
(/usr/bin/time -v ./esa data/proteins.200MB 50000    100)   &> peak_ram/esa_proteins200_50000_100.txt

## change tau
(/usr/bin/time -v ./esa data/english.200MB  5        100)   &> peak_ram/esa_english200_5_100.txt
(/usr/bin/time -v ./esa data/english.200MB  50       100)   &> peak_ram/esa_english200_50_100.txt
(/usr/bin/time -v ./esa data/english.200MB  500      100)   &> peak_ram/esa_english200_500_100.txt
(/usr/bin/time -v ./esa data/english.200MB  5000     100)   &> peak_ram/esa_english200_5000_100.txt
(/usr/bin/time -v ./esa data/english.200MB  50000    100)   &> peak_ram/esa_english200_50000_100.txt

## change tau
(/usr/bin/time -v ./esa data/sources.200MB  5        100)   &> peak_ram/esa_sources200_5_100.txt
(/usr/bin/time -v ./esa data/sources.200MB  50       100)   &> peak_ram/esa_sources200_50_100.txt
(/usr/bin/time -v ./esa data/sources.200MB  500      100)   &> peak_ram/esa_sources200_500_100.txt
(/usr/bin/time -v ./esa data/sources.200MB  5000     100)   &> peak_ram/esa_sources200_5000_100.txt
(/usr/bin/time -v ./esa data/sources.200MB  50000    100)   &> peak_ram/esa_sources200_50000_100.txt

## change tau
(/usr/bin/time -v ./esa data/dblp.xml.200MB 5        100)   &> peak_ram/esa_xml200_5_100.txt
(/usr/bin/time -v ./esa data/dblp.xml.200MB 50       100)   &> peak_ram/esa_xml200_50_100.txt
(/usr/bin/time -v ./esa data/dblp.xml.200MB 500      100)   &> peak_ram/esa_xml200_500_100.txt
(/usr/bin/time -v ./esa data/dblp.xml.200MB 5000     100)   &> peak_ram/esa_xml200_5000_100.txt
(/usr/bin/time -v ./esa data/dblp.xml.200MB 50000    100)   &> peak_ram/esa_xml200_50000_100.txt

