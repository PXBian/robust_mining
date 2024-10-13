#!/bin/bash

(/usr/bin/time -v ./main dblp.xml.50MB 100 100) &> peak_ram/mem_xml50_100_100.txt
(/usr/bin/time -v ./main dblp.xml.50MB 100 1000) &> peak_ram/mem_xml50_100_1000.txt
(/usr/bin/time -v ./main dblp.xml.50MB 100 2000) &> peak_ram/mem_xml50_100_2000.txt
(/usr/bin/time -v ./main dblp.xml.50MB 100 10000) &> peak_ram/mem_xml50_100_10000.txt