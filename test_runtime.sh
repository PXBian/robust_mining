#!/bin/bash

mkdir peak_ram
rm runtime_details.csv
gunzip data/*.gz
make all

# (/usr/bin/time -v ./main data/dna.50MB 100 100)      &> peak_ram/mem_dna50_100_100.txt
# (/usr/bin/time -v ./main data/dna.50MB 100 1000)     &> peak_ram/mem_dna50_100_1000.txt
# (/usr/bin/time -v ./main data/dna.50MB 100 10000)    &> peak_ram/mem_dna50_100_10000.txt
# (/usr/bin/time -v ./main data/dna.50MB 1000 100)     &> peak_ram/mem_dna50_1000_100.txt
# (/usr/bin/time -v ./main data/dna.50MB 1000 1000)    &> peak_ram/mem_dna50_1000_1000.txt
# (/usr/bin/time -v ./main data/dna.50MB 1000 10000)   &> peak_ram/mem_dna50_1000_10000.txt
# (/usr/bin/time -v ./main data/dna.50MB 10000 100)    &> peak_ram/mem_dna50_10000_100.txt
# (/usr/bin/time -v ./main data/dna.50MB 10000 1000)   &> peak_ram/mem_dna50_10000_1000.txt
# (/usr/bin/time -v ./main data/dna.50MB 10000 10000)  &> peak_ram/mem_dna50_10000_10000.txt
# (/usr/bin/time -v ./main data/dna.100MB 100 100)     &> peak_ram/mem_dna100_100_100.txt
# (/usr/bin/time -v ./main data/dna.100MB 100 1000)    &> peak_ram/mem_dna100_100_1000.txt
# (/usr/bin/time -v ./main data/dna.100MB 100 10000)   &> peak_ram/mem_dna100_100_10000.txt
(/usr/bin/time -v ./main data/dna.100MB 1000 100)    &> peak_ram/mem_dna100_1000_100.txt
# (/usr/bin/time -v ./main data/dna.100MB 1000 1000)   &> peak_ram/mem_dna100_1000_1000.txt
# (/usr/bin/time -v ./main data/dna.100MB 1000 10000)  &> peak_ram/mem_dna100_1000_10000.txt
# (/usr/bin/time -v ./main data/dna.100MB 10000 100)   &> peak_ram/mem_dna100_10000_100.txt
# (/usr/bin/time -v ./main data/dna.100MB 10000 1000)  &> peak_ram/mem_dna100_10000_1000.txt
# (/usr/bin/time -v ./main data/dna.100MB 10000 10000) &> peak_ram/mem_dna100_10000_10000.txt
# (/usr/bin/time -v ./main data/dna.200MB 100 100)     &> peak_ram/mem_dna200_100_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 100 1000)    &> peak_ram/mem_dna200_100_1000.txt
# (/usr/bin/time -v ./main data/dna.200MB 100 10000)   &> peak_ram/mem_dna200_100_10000.txt
# (/usr/bin/time -v ./main data/dna.200MB 1000 100)    &> peak_ram/mem_dna200_1000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 1000 1000)   &> peak_ram/mem_dna200_1000_1000.txt
# (/usr/bin/time -v ./main data/dna.200MB 1000 10000)  &> peak_ram/mem_dna200_1000_10000.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000 100)   &> peak_ram/mem_dna200_10000_100.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000 1000)  &> peak_ram/mem_dna200_10000_1000.txt
# (/usr/bin/time -v ./main data/dna.200MB 10000 10000) &> peak_ram/mem_dna200_10000_10000.txt


# (/usr/bin/time -v ./main data/proteins.50MB 100 100)     &> peak_ram/mem_proteins50_100_100.txt
# (/usr/bin/time -v ./main data/proteins.50MB 100 1000)    &> peak_ram/mem_proteins50_100_1000.txt
# (/usr/bin/time -v ./main data/proteins.50MB 100 10000)   &> peak_ram/mem_proteins50_100_10000.txt
# (/usr/bin/time -v ./main data/proteins.50MB 1000 100)    &> peak_ram/mem_proteins50_1000_100.txt
# (/usr/bin/time -v ./main data/proteins.50MB 1000 1000)   &> peak_ram/mem_proteins50_1000_1000.txt
# (/usr/bin/time -v ./main data/proteins.50MB 1000 10000)  &> peak_ram/mem_proteins50_1000_10000.txt
# (/usr/bin/time -v ./main data/proteins.50MB 10000 100)   &> peak_ram/mem_proteins50_10000_100.txt
# (/usr/bin/time -v ./main data/proteins.50MB 10000 1000)  &> peak_ram/mem_proteins50_10000_1000.txt
# (/usr/bin/time -v ./main data/proteins.50MB 10000 10000) &> peak_ram/mem_proteins50_10000_10000.txt
# (/usr/bin/time -v ./main data/proteins.100MB 100 100)    &> peak_ram/mem_proteins100_100_100.txt
# (/usr/bin/time -v ./main data/proteins.100MB 100 1000)   &> peak_ram/mem_proteins100_100_1000.txt
# (/usr/bin/time -v ./main data/proteins.100MB 100 10000)  &> peak_ram/mem_proteins100_100_10000.txt
# (/usr/bin/time -v ./main data/proteins.100MB 1000 100)   &> peak_ram/mem_proteins100_1000_100.txt
# (/usr/bin/time -v ./main data/proteins.100MB 1000 1000)  &> peak_ram/mem_proteins100_1000_1000.txt
# (/usr/bin/time -v ./main data/proteins.100MB 1000 10000) &> peak_ram/mem_proteins100_1000_10000.txt
# (/usr/bin/time -v ./main data/proteins.100MB 10000 100)  &> peak_ram/mem_proteins100_10000_100.txt
# (/usr/bin/time -v ./main data/proteins.100MB 10000 1000) &> peak_ram/mem_proteins100_10000_1000.txt
# (/usr/bin/time -v ./main data/proteins.100MB 10000 10000) &> peak_ram/mem_proteins100_10000_10000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 100 100)    &> peak_ram/mem_proteins200_100_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 100 1000)   &> peak_ram/mem_proteins200_100_1000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 100 10000)  &> peak_ram/mem_proteins200_100_10000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 1000 100)   &> peak_ram/mem_proteins200_1000_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 1000 1000)  &> peak_ram/mem_proteins200_1000_1000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 1000 10000) &> peak_ram/mem_proteins200_1000_10000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000 100)  &> peak_ram/mem_proteins200_10000_100.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000 1000) &> peak_ram/mem_proteins200_10000_1000.txt
# (/usr/bin/time -v ./main data/proteins.200MB 10000 10000) &> peak_ram/mem_proteins200_10000_10000.txt


# (/usr/bin/time -v ./main data/english.50MB 100 100)      &> peak_ram/mem_english50_100_100.txt
# (/usr/bin/time -v ./main data/english.50MB 100 1000)     &> peak_ram/mem_english50_100_1000.txt
# (/usr/bin/time -v ./main data/english.50MB 100 10000)    &> peak_ram/mem_english50_100_10000.txt
# (/usr/bin/time -v ./main data/english.50MB 1000 100)     &> peak_ram/mem_english50_1000_100.txt
# (/usr/bin/time -v ./main data/english.50MB 1000 1000)    &> peak_ram/mem_english50_1000_1000.txt
# (/usr/bin/time -v ./main data/english.50MB 1000 10000)   &> peak_ram/mem_english50_1000_10000.txt
# (/usr/bin/time -v ./main data/english.50MB 10000 100)    &> peak_ram/mem_english50_10000_100.txt
# (/usr/bin/time -v ./main data/english.50MB 10000 1000)   &> peak_ram/mem_english50_10000_1000.txt
# (/usr/bin/time -v ./main data/english.50MB 10000 10000)  &> peak_ram/mem_english50_10000_10000.txt
# (/usr/bin/time -v ./main data/english.100MB 100 100)     &> peak_ram/mem_english100_100_100.txt
# (/usr/bin/time -v ./main data/english.100MB 100 1000)    &> peak_ram/mem_english100_100_1000.txt
# (/usr/bin/time -v ./main data/english.100MB 100 10000)   &> peak_ram/mem_english100_100_10000.txt
# (/usr/bin/time -v ./main data/english.100MB 1000 100)    &> peak_ram/mem_english100_1000_100.txt
# (/usr/bin/time -v ./main data/english.100MB 1000 1000)   &> peak_ram/mem_english100_1000_1000.txt
# (/usr/bin/time -v ./main data/english.100MB 1000 10000)  &> peak_ram/mem_english100_1000_10000.txt
# (/usr/bin/time -v ./main data/english.100MB 10000 100)   &> peak_ram/mem_english100_10000_100.txt
# (/usr/bin/time -v ./main data/english.100MB 10000 1000)  &> peak_ram/mem_english100_10000_1000.txt
# (/usr/bin/time -v ./main data/english.100MB 10000 10000) &> peak_ram/mem_english100_10000_10000.txt
# (/usr/bin/time -v ./main data/english.200MB 100 100)     &> peak_ram/mem_english200_100_100.txt
# (/usr/bin/time -v ./main data/english.200MB 100 1000)    &> peak_ram/mem_english200_100_1000.txt
# (/usr/bin/time -v ./main data/english.200MB 100 10000)   &> peak_ram/mem_english200_100_10000.txt
# (/usr/bin/time -v ./main data/english.200MB 1000 100)    &> peak_ram/mem_english200_1000_100.txt
# (/usr/bin/time -v ./main data/english.200MB 1000 1000)   &> peak_ram/mem_english200_1000_1000.txt
# (/usr/bin/time -v ./main data/english.200MB 1000 10000)  &> peak_ram/mem_english200_1000_10000.txt
# (/usr/bin/time -v ./main data/english.200MB 10000 100)   &> peak_ram/mem_english200_10000_100.txt
# (/usr/bin/time -v ./main data/english.200MB 10000 1000)  &> peak_ram/mem_english200_10000_1000.txt
# (/usr/bin/time -v ./main data/english.200MB 10000 10000) &> peak_ram/mem_english200_10000_10000.txt


# (/usr/bin/time -v ./main data/sources.50MB 100 100)      &> peak_ram/mem_sources50_100_100.txt
# (/usr/bin/time -v ./main data/sources.50MB 100 1000)     &> peak_ram/mem_sources50_100_1000.txt
# (/usr/bin/time -v ./main data/sources.50MB 100 10000)    &> peak_ram/mem_sources50_100_10000.txt
# (/usr/bin/time -v ./main data/sources.50MB 1000 100)     &> peak_ram/mem_sources50_1000_100.txt
# (/usr/bin/time -v ./main data/sources.50MB 1000 1000)    &> peak_ram/mem_sources50_1000_1000.txt
# (/usr/bin/time -v ./main data/sources.50MB 1000 10000)   &> peak_ram/mem_sources50_1000_10000.txt
# (/usr/bin/time -v ./main data/sources.50MB 10000 100)    &> peak_ram/mem_sources50_10000_100.txt
# (/usr/bin/time -v ./main data/sources.50MB 10000 1000)   &> peak_ram/mem_sources50_10000_1000.txt
# (/usr/bin/time -v ./main data/sources.50MB 10000 10000)  &> peak_ram/mem_sources50_10000_10000.txt
# (/usr/bin/time -v ./main data/sources.100MB 100 100)     &> peak_ram/mem_sources100_100_100.txt
# (/usr/bin/time -v ./main data/sources.100MB 100 1000)    &> peak_ram/mem_sources100_100_1000.txt
# (/usr/bin/time -v ./main data/sources.100MB 100 10000)   &> peak_ram/mem_sources100_100_10000.txt
# (/usr/bin/time -v ./main data/sources.100MB 1000 100)    &> peak_ram/mem_sources100_1000_100.txt
# (/usr/bin/time -v ./main data/sources.100MB 1000 1000)   &> peak_ram/mem_sources100_1000_1000.txt
# (/usr/bin/time -v ./main data/sources.100MB 1000 10000)  &> peak_ram/mem_sources100_1000_10000.txt
# (/usr/bin/time -v ./main data/sources.100MB 10000 100)   &> peak_ram/mem_sources100_10000_100.txt
# (/usr/bin/time -v ./main data/sources.100MB 10000 1000)  &> peak_ram/mem_sources100_10000_1000.txt
# (/usr/bin/time -v ./main data/sources.100MB 10000 10000) &> peak_ram/mem_sources100_10000_10000.txt
# (/usr/bin/time -v ./main data/sources.200MB 100 100)     &> peak_ram/mem_sources200_100_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 100 1000)    &> peak_ram/mem_sources200_100_1000.txt
# (/usr/bin/time -v ./main data/sources.200MB 100 10000)   &> peak_ram/mem_sources200_100_10000.txt
# (/usr/bin/time -v ./main data/sources.200MB 1000 100)    &> peak_ram/mem_sources200_1000_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 1000 1000)   &> peak_ram/mem_sources200_1000_1000.txt
# (/usr/bin/time -v ./main data/sources.200MB 1000 10000)  &> peak_ram/mem_sources200_1000_10000.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000 100)   &> peak_ram/mem_sources200_10000_100.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000 1000)  &> peak_ram/mem_sources200_10000_1000.txt
# (/usr/bin/time -v ./main data/sources.200MB 10000 10000) &> peak_ram/mem_sources200_10000_10000.txt


# (/usr/bin/time -v ./main data/dblp.xml.50MB 100 100)     &> peak_ram/mem_xml50_100_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.50MB 100 1000)    &> peak_ram/mem_xml50_100_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.50MB 100 10000)   &> peak_ram/mem_xml50_100_10000.txt
# (/usr/bin/time -v ./main data/dblp.xml.50MB 1000 100)    &> peak_ram/mem_xml50_1000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.50MB 1000 1000)   &> peak_ram/mem_xml50_1000_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.50MB 1000 10000)  &> peak_ram/mem_xml50_1000_10000.txt
# (/usr/bin/time -v ./main data/dblp.xml.50MB 10000 100)   &> peak_ram/mem_xml50_10000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.50MB 10000 1000)  &> peak_ram/mem_xml50_10000_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.50MB 10000 10000) &> peak_ram/mem_xml50_10000_10000.txt
# (/usr/bin/time -v ./main data/dblp.xml.100MB 100 100)    &> peak_ram/mem_xml100_100_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.100MB 100 1000)   &> peak_ram/mem_xml100_100_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.100MB 100 10000)  &> peak_ram/mem_xml100_100_10000.txt
(/usr/bin/time -v ./main data/dblp.xml.100MB 1000 100)   &> peak_ram/mem_xml100_1000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.100MB 1000 1000)  &> peak_ram/mem_xml100_1000_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.100MB 1000 10000) &> peak_ram/mem_xml100_1000_10000.txt
# (/usr/bin/time -v ./main data/dblp.xml.100MB 10000 100)  &> peak_ram/mem_xml100_10000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.100MB 10000 1000) &> peak_ram/mem_xml100_10000_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.100MB 10000 10000) &> peak_ram/mem_xml100_10000_10000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 100 100)    &> peak_ram/mem_xml200_100_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 100 1000)   &> peak_ram/mem_xml200_100_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 100 10000)  &> peak_ram/mem_xml200_100_10000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 1000 100)   &> peak_ram/mem_xml200_1000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 1000 1000)  &> peak_ram/mem_xml200_1000_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 1000 10000) &> peak_ram/mem_xml200_1000_10000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 100)  &> peak_ram/mem_xml200_10000_100.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 1000) &> peak_ram/mem_xml200_10000_1000.txt
# (/usr/bin/time -v ./main data/dblp.xml.200MB 10000 10000) &> peak_ram/mem_xml200_10000_10000.txt

