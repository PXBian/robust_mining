#!/bin/bash

mkdir peak_ram
rm runtime_details.csv
gunzip *.gz

(/usr/bin/time -v ./main dblp.xml.50MB 100 100)     &> peak_ram/mem_xml50_100_100.txt
(/usr/bin/time -v ./main dblp.xml.50MB 100 1000)    &> peak_ram/mem_xml50_100_1000.txt
(/usr/bin/time -v ./main dblp.xml.50MB 100 10000)   &> peak_ram/mem_xml50_100_10000.txt
(/usr/bin/time -v ./main dblp.xml.50MB 1000 100)    &> peak_ram/mem_xml50_1000_100.txt
(/usr/bin/time -v ./main dblp.xml.50MB 1000 1000)   &> peak_ram/mem_xml50_1000_1000.txt
(/usr/bin/time -v ./main dblp.xml.50MB 1000 10000)  &> peak_ram/mem_xml50_1000_10000.txt
(/usr/bin/time -v ./main dblp.xml.50MB 10000 100)   &> peak_ram/mem_xml50_10000_100.txt
(/usr/bin/time -v ./main dblp.xml.50MB 10000 1000)  &> peak_ram/mem_xml50_10000_1000.txt
(/usr/bin/time -v ./main dblp.xml.50MB 10000 10000) &> peak_ram/mem_xml50_10000_10000.txt


(/usr/bin/time -v ./main dna.50MB 100 100)      &> peak_ram/mem_dna50_100_100.txt
(/usr/bin/time -v ./main dna.50MB 100 1000)     &> peak_ram/mem_dna50_100_1000.txt
(/usr/bin/time -v ./main dna.50MB 100 10000)    &> peak_ram/mem_dna50_100_10000.txt
(/usr/bin/time -v ./main dna.50MB 1000 100)     &> peak_ram/mem_dna50_1000_100.txt
(/usr/bin/time -v ./main dna.50MB 1000 1000)    &> peak_ram/mem_dna50_1000_1000.txt
(/usr/bin/time -v ./main dna.50MB 1000 10000)   &> peak_ram/mem_dna50_1000_10000.txt
(/usr/bin/time -v ./main dna.50MB 10000 100)    &> peak_ram/mem_dna50_10000_100.txt
(/usr/bin/time -v ./main dna.50MB 10000 1000)   &> peak_ram/mem_dna50_10000_1000.txt
(/usr/bin/time -v ./main dna.50MB 10000 10000)  &> peak_ram/mem_dna50_10000_10000.txt