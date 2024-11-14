#!/bin/bash

rm error*
rm testing_results_summary

## Compile MAIN
make all
g++ -O3 -DNDEBUG -I ~/include -L ~/lib runs.hpp intervaltree.hpp main_ESA.cpp -o esa -lsdsl -ldivsufsort -ldivsufsort64
## Compile BASELINE
g++ baseline.cc -o baseline
## Compile test program
g++ test_random.cpp -o test

./test
