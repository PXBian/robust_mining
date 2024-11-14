#!/bin/bash

mkdir peak_ram
mkdir output
make all

(/usr/bin/time -v ./main data/dna.200MB 2       100)   &> peak_ram/ex_dna200_2_100.txt
(/usr/bin/time -v ./main data/proteins.200MB 2  100)   &> peak_ram/ex_proteins200_2_100.txt
(/usr/bin/time -v ./main data/english.200MB 2   100)   &> peak_ram/ex_english200_2_100.txt


# ## change tau
# (/usr/bin/time -v ./main data/dna.200MB 10       100)   &> peak_ram/ex_dna200_10_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 100      100)   &> peak_ram/ex_dna200_100_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 1000     100)   &> peak_ram/ex_dna200_1000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000    100)   &> peak_ram/ex_dna200_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 100000   100)   &> peak_ram/ex_dna200_100000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 1000000  100)   &> peak_ram/ex_dna200_1000000_100.txt
# ## change k
# (/usr/bin/time -v ./main data/dna.200MB 10000 10     )    &> peak_ram/ex_dna200_10000_10.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000 100    )    &> peak_ram/ex_dna200_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000 1000   )    &> peak_ram/ex_dna200_10000_1000.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000 10000  )    &> peak_ram/ex_dna200_10000_10000.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000 100000 )    &> peak_ram/ex_dna200_10000_100000.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000 1000000)    &> peak_ram/ex_dna200_10000_1000000.txt


# # ## change tau
# (/usr/bin/time -v ./main data/proteins.200MB 10       100)   &> peak_ram/ex_proteins200_10_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 100      100)   &> peak_ram/ex_proteins200_100_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 1000     100)   &> peak_ram/ex_proteins200_1000_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000    100)   &> peak_ram/ex_proteins200_10000_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 100000   100)   &> peak_ram/ex_proteins200_100000_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 1000000  100)   &> peak_ram/ex_proteins200_1000000_100.txt
# ## change k
# (/usr/bin/time -v ./main data/proteins.200MB 10000 10     )    &> peak_ram/ex_proteins200_10000_10.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000 100    )    &> peak_ram/ex_proteins200_10000_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000 1000   )    &> peak_ram/ex_proteins200_10000_1000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000 10000  )    &> peak_ram/ex_proteins200_10000_10000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000 100000 )    &> peak_ram/ex_proteins200_10000_100000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000 1000000)    &> peak_ram/ex_proteins200_10000_1000000.txt


# ## change tau
# (/usr/bin/time -v ./main data/english.200MB 10       100)   &> peak_ram/ex_english200_10_100.txt
# (/usr/bin/time -v ./main data/english.200MB 100      100)   &> peak_ram/ex_english200_100_100.txt
# (/usr/bin/time -v ./main data/english.200MB 1000     100)   &> peak_ram/ex_english200_1000_100.txt
# (/usr/bin/time -v ./main data/english.200MB 10000    100)   &> peak_ram/ex_english200_10000_100.txt
# (/usr/bin/time -v ./main data/english.200MB 100000   100)   &> peak_ram/ex_english200_100000_100.txt
# (/usr/bin/time -v ./main data/english.200MB 1000000  100)   &> peak_ram/ex_english200_1000000_100.txt
# # change k
# (/usr/bin/time -v ./main data/english.200MB 10000 10     )    &> peak_ram/ex_english200_10000_10.txt
# (/usr/bin/time -v ./main data/english.200MB 10000 100    )    &> peak_ram/ex_english200_10000_100.txt
# (/usr/bin/time -v ./main data/english.200MB 10000 1000   )    &> peak_ram/ex_english200_10000_1000.txt
# (/usr/bin/time -v ./main data/english.200MB 10000 10000  )    &> peak_ram/ex_english200_10000_10000.txt
# (/usr/bin/time -v ./main data/english.200MB 10000 100000 )    &> peak_ram/ex_english200_10000_100000.txt
# (/usr/bin/time -v ./main data/english.200MB 10000 1000000)    &> peak_ram/ex_english200_10000_1000000.txt


# ## change tau
# (/usr/bin/time -v ./main data/sources.200MB 10       100)   &> peak_ram/ex_sources200_10_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 100      100)   &> peak_ram/ex_sources200_100_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 1000     100)   &> peak_ram/ex_sources200_1000_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000    100)   &> peak_ram/ex_sources200_10000_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 100000   100)   &> peak_ram/ex_sources200_100000_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 1000000  100)   &> peak_ram/ex_sources200_1000000_100.txt
# ## change k
# (/usr/bin/time -v ./main data/sources.200MB 10000 10     )    &> peak_ram/ex_sources200_10000_10.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000 100    )    &> peak_ram/ex_sources200_10000_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000 1000   )    &> peak_ram/ex_sources200_10000_1000.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000 10000  )    &> peak_ram/ex_sources200_10000_10000.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000 100000 )    &> peak_ram/ex_sources200_10000_100000.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000 1000000)    &> peak_ram/ex_sources200_10000_1000000.txt


# ## change tau
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10       100)   &> peak_ram/ex_xml200_10_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 100      100)   &> peak_ram/ex_xml200_100_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 1000     100)   &> peak_ram/ex_xml200_1000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000    100)   &> peak_ram/ex_xml200_10000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 100000   100)   &> peak_ram/ex_xml200_100000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 1000000  100)   &> peak_ram/ex_xml200_1000000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000000 100)   &> peak_ram/ex_xml200_10000000_100.txt
# ## change k
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 10     )    &> peak_ram/ex_xml200_10000_10.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 100    )    &> peak_ram/ex_xml200_10000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 1000   )    &> peak_ram/ex_xml200_10000_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 10000  )    &> peak_ram/ex_xml200_10000_10000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 100000 )    &> peak_ram/ex_xml200_10000_100000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 500000 )    &> peak_ram/ex_xml200_10000_500000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 1000000)    &> peak_ram/ex_xml200_10000_1000000.txt



# # ## change n
# (/usr/bin/time -v ./main data/dna.200MB_25MB   10000 100)    &> peak_ram/ex_dna200_25MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_50MB   10000 100)    &> peak_ram/ex_dna200_50MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_75MB   10000 100)    &> peak_ram/ex_dna200_75MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_100MB  10000 100)    &> peak_ram/ex_dna200_100MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_125MB  10000 100)    &> peak_ram/ex_dna200_125MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_150MB  10000 100)    &> peak_ram/ex_dna200_150MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB_175MB  10000 100)    &> peak_ram/ex_dna200_175MB_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB        10000 100)    &> peak_ram/ex_dna200_10000_100.txt

