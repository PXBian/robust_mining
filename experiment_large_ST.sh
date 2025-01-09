#!/bin/bash

mkdir peak_ram
mkdir output
make all


(/usr/bin/time -v ./main data/dna.200MB 10000000    1000000)    &> peak_ram/st_dna200_10000000_1000000.txt
(/usr/bin/time -v ./main data/dna.200MB 20000000    1000000)    &> peak_ram/st_dna200_20000000_1000000.txt
(/usr/bin/time -v ./main data/dna.200MB 40000000    1000000)    &> peak_ram/st_dna200_40000000_1000000.txt
(/usr/bin/time -v ./main data/dna.200MB 60000000    1000000)    &> peak_ram/st_dna200_60000000_1000000.txt

(/usr/bin/time -v ./main data/dna.200MB 10000000    10000000)   &> peak_ram/st_dna200_10000000_10000000.txt
(/usr/bin/time -v ./main data/dna.200MB 20000000    10000000)   &> peak_ram/st_dna200_20000000_10000000.txt
(/usr/bin/time -v ./main data/dna.200MB 40000000    10000000)   &> peak_ram/st_dna200_40000000_10000000.txt
(/usr/bin/time -v ./main data/dna.200MB 60000000    10000000)   &> peak_ram/st_dna200_60000000_10000000.txt

(/usr/bin/time -v ./main data/dna.200MB 10000000    100000000)  &> peak_ram/st_dna200_10000000_100000000.txt
(/usr/bin/time -v ./main data/dna.200MB 20000000    100000000)  &> peak_ram/st_dna200_20000000_100000000.txt
(/usr/bin/time -v ./main data/dna.200MB 40000000    100000000)  &> peak_ram/st_dna200_40000000_100000000.txt
(/usr/bin/time -v ./main data/dna.200MB 60000000    100000000)  &> peak_ram/st_dna200_60000000_100000000.txt



(/usr/bin/time -v ./main data/proteins.200MB 2000000    1000000)     &> peak_ram/st_proteins200_2000000_1000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 4000000    1000000)     &> peak_ram/st_proteins200_4000000_1000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 6000000    1000000)     &> peak_ram/st_proteins200_6000000_1000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 8000000    1000000)     &> peak_ram/st_proteins200_8000000_1000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 10000000   1000000)     &> peak_ram/st_proteins200_10000000_1000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 15000000   1000000)     &> peak_ram/st_proteins200_15000000_1000000.txt

(/usr/bin/time -v ./main data/proteins.200MB 2000000    10000000)    &> peak_ram/st_proteins200_2000000_10000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 4000000    10000000)    &> peak_ram/st_proteins200_4000000_10000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 6000000    10000000)    &> peak_ram/st_proteins200_6000000_10000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 8000000    10000000)    &> peak_ram/st_proteins200_8000000_10000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 10000000   10000000)    &> peak_ram/st_proteins200_10000000_10000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 15000000   10000000)    &> peak_ram/st_proteins200_15000000_10000000.txt

(/usr/bin/time -v ./main data/proteins.200MB 2000000    100000000)   &> peak_ram/st_proteins200_2000000_100000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 4000000    100000000)   &> peak_ram/st_proteins200_4000000_100000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 6000000    100000000)   &> peak_ram/st_proteins200_6000000_100000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 8000000    100000000)   &> peak_ram/st_proteins200_8000000_100000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 10000000   100000000)   &> peak_ram/st_proteins200_10000000_100000000.txt
(/usr/bin/time -v ./main data/proteins.200MB 15000000   100000000)   &> peak_ram/st_proteins200_15000000_100000000.txt



(/usr/bin/time -v ./main data/english.200MB  2000000    1000000)     &> peak_ram/st_english200_2000000_1000000.txt
(/usr/bin/time -v ./main data/english.200MB  4000000    1000000)     &> peak_ram/st_english200_4000000_1000000.txt
(/usr/bin/time -v ./main data/english.200MB  6000000    1000000)     &> peak_ram/st_english200_6000000_1000000.txt
(/usr/bin/time -v ./main data/english.200MB  8000000    1000000)     &> peak_ram/st_english200_8000000_1000000.txt
(/usr/bin/time -v ./main data/english.200MB  10000000   1000000)     &> peak_ram/st_english200_10000000_1000000.txt
(/usr/bin/time -v ./main data/english.200MB  15000000   1000000)     &> peak_ram/st_english200_15000000_1000000.txt

(/usr/bin/time -v ./main data/english.200MB  2000000    10000000)    &> peak_ram/st_english200_2000000_10000000.txt
(/usr/bin/time -v ./main data/english.200MB  4000000    10000000)    &> peak_ram/st_english200_4000000_10000000.txt
(/usr/bin/time -v ./main data/english.200MB  6000000    10000000)    &> peak_ram/st_english200_6000000_10000000.txt
(/usr/bin/time -v ./main data/english.200MB  8000000    10000000)    &> peak_ram/st_english200_8000000_10000000.txt
(/usr/bin/time -v ./main data/english.200MB  10000000   10000000)    &> peak_ram/st_english200_10000000_10000000.txt
(/usr/bin/time -v ./main data/english.200MB  15000000   10000000)    &> peak_ram/st_english200_15000000_10000000.txt

(/usr/bin/time -v ./main data/english.200MB  2000000    100000000)   &> peak_ram/st_english200_2000000_100000000.txt
(/usr/bin/time -v ./main data/english.200MB  4000000    100000000)   &> peak_ram/st_english200_4000000_100000000.txt
(/usr/bin/time -v ./main data/english.200MB  6000000    100000000)   &> peak_ram/st_english200_6000000_100000000.txt
(/usr/bin/time -v ./main data/english.200MB  8000000    100000000)   &> peak_ram/st_english200_8000000_100000000.txt
(/usr/bin/time -v ./main data/english.200MB  10000000   100000000)   &> peak_ram/st_english200_10000000_100000000.txt
(/usr/bin/time -v ./main data/english.200MB  15000000   100000000)   &> peak_ram/st_english200_15000000_100000000.txt



(/usr/bin/time -v ./main data/sources.200MB  2000000    1000000)     &> peak_ram/st_source200_2000000_1000000.txt
(/usr/bin/time -v ./main data/sources.200MB  4000000    1000000)     &> peak_ram/st_source200_4000000_1000000.txt
(/usr/bin/time -v ./main data/sources.200MB  6000000    1000000)     &> peak_ram/st_source200_6000000_1000000.txt
(/usr/bin/time -v ./main data/sources.200MB  8000000    1000000)     &> peak_ram/st_source200_8000000_1000000.txt
(/usr/bin/time -v ./main data/sources.200MB  10000000   1000000)     &> peak_ram/st_source200_10000000_1000000.txt
(/usr/bin/time -v ./main data/sources.200MB  15000000   1000000)     &> peak_ram/st_source200_15000000_1000000.txt

(/usr/bin/time -v ./main data/sources.200MB  2000000    10000000)    &> peak_ram/st_source200_2000000_10000000.txt
(/usr/bin/time -v ./main data/sources.200MB  4000000    10000000)    &> peak_ram/st_source200_4000000_10000000.txt
(/usr/bin/time -v ./main data/sources.200MB  6000000    10000000)    &> peak_ram/st_source200_6000000_10000000.txt
(/usr/bin/time -v ./main data/sources.200MB  8000000    10000000)    &> peak_ram/st_source200_8000000_10000000.txt
(/usr/bin/time -v ./main data/sources.200MB  10000000   10000000)    &> peak_ram/st_source200_10000000_10000000.txt
(/usr/bin/time -v ./main data/sources.200MB  15000000   10000000)    &> peak_ram/st_source200_15000000_10000000.txt

(/usr/bin/time -v ./main data/sources.200MB  2000000    100000000)   &> peak_ram/st_source200_2000000_100000000.txt
(/usr/bin/time -v ./main data/sources.200MB  4000000    100000000)   &> peak_ram/st_source200_4000000_100000000.txt
(/usr/bin/time -v ./main data/sources.200MB  6000000    100000000)   &> peak_ram/st_source200_6000000_100000000.txt
(/usr/bin/time -v ./main data/sources.200MB  8000000    100000000)   &> peak_ram/st_source200_8000000_100000000.txt
(/usr/bin/time -v ./main data/sources.200MB  10000000   100000000)   &> peak_ram/st_source200_10000000_100000000.txt
(/usr/bin/time -v ./main data/sources.200MB  15000000   100000000)   &> peak_ram/st_source200_15000000_100000000.txt



(/usr/bin/time -v ./main data/dblp.xml.200MB  2000000    1000000)    &> peak_ram/st_xml200_2000000_1000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  4000000    1000000)    &> peak_ram/st_xml200_4000000_1000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  6000000    1000000)    &> peak_ram/st_xml200_6000000_1000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  8000000    1000000)    &> peak_ram/st_xml200_8000000_1000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  10000000   1000000)    &> peak_ram/st_xml200_10000000_1000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  15000000   1000000)    &> peak_ram/st_xml200_15000000_1000000.txt

(/usr/bin/time -v ./main data/dblp.xml.200MB  2000000    10000000)   &> peak_ram/st_xml200_2000000_10000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  4000000    10000000)   &> peak_ram/st_xml200_4000000_10000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  6000000    10000000)   &> peak_ram/st_xml200_6000000_10000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  8000000    10000000)   &> peak_ram/st_xml200_8000000_10000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  10000000   10000000)   &> peak_ram/st_xml200_10000000_10000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  15000000   10000000)   &> peak_ram/st_xml200_15000000_10000000.txt

(/usr/bin/time -v ./main data/dblp.xml.200MB  2000000    100000000)  &> peak_ram/st_xml200_2000000_100000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  4000000    100000000)  &> peak_ram/st_xml200_4000000_100000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  6000000    100000000)  &> peak_ram/st_xml200_6000000_100000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  8000000    100000000)  &> peak_ram/st_xml200_8000000_100000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  10000000   100000000)  &> peak_ram/st_xml200_10000000_100000000.txt
(/usr/bin/time -v ./main data/dblp.xml.200MB  15000000   100000000)  &> peak_ram/st_xml200_15000000_100000000.txt
