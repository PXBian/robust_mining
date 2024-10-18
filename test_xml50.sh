#!/bin/bash

mkdir peak_ram
# rm runtime_details.csv
gunzip *.gz

# (/usr/bin/time -v ./main dblp.xml.50MB 100 100)     &> peak_ram/mem_xml50_100_100.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 100 1000)    &> peak_ram/mem_xml50_100_1000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 100 10000)   &> peak_ram/mem_xml50_100_10000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 1000 100)    &> peak_ram/mem_xml50_1000_100.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 1000 1000)   &> peak_ram/mem_xml50_1000_1000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 1000 10000)  &> peak_ram/mem_xml50_1000_10000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 10000 100)   &> peak_ram/mem_xml50_10000_100.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 10000 1000)  &> peak_ram/mem_xml50_10000_1000.txt
# (/usr/bin/time -v ./main dblp.xml.50MB 10000 10000) &> peak_ram/mem_xml50_10000_10000.txt


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
(/usr/bin/time -v ./main dna.50MB 1000 80000)   &> peak_ram/mem_dna50_1000_80000.txt
(/usr/bin/time -v ./main dna.50MB 1000 90000)   &> peak_ram/mem_dna50_1000_90000.txt
(/usr/bin/time -v ./main dna.50MB 1000 100000)  &> peak_ram/mem_dna50_1000_100000.txt



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