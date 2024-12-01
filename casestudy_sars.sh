#!/bin/bash

make all
g++ -O3 -std=c++11 case_study.cpp karp_rabin_hashing.hpp utils.cpp suffixtree.hpp -o case
mkdir output
mkdir peak_ram

(
    # (/usr/bin/time -v ./case data/sars_1435K.fna 50    10   data/sars_1.txt)   &> peak_ram/casestudy_sars_50_10.txt     
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   10   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_10.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   10   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_10.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   10   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_10.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  10   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_10.txt   

    # (/usr/bin/time -v ./case data/sars_1435K.fna 50    20   data/sars_1.txt)   &> peak_ram/casestudy_sars_50_20.txt     
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   20   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_20.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   20   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_20.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   20   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_20.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  20   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_20.txt   

    # (/usr/bin/time -v ./case data/sars_1435K.fna 50    50   data/sars_1.txt)   &> peak_ram/casestudy_sars_50_50.txt     
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   50   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_50.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   50   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_50.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   50   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_50.txt    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  50   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_50.txt   

    # (/usr/bin/time -v ./case data/sars_1435K.fna 50    100   data/sars_1.txt)   &> peak_ram/casestudy_sars_50_100.txt   
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   100   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_100.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   100   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_100.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   100   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_100.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  100   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_100.txt 


    # (/usr/bin/time -v ./case data/sars_1435K.fna 50    150   data/sars_1.txt)   &> peak_ram/casestudy_sars_50_150.txt   
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   150   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_150.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   150   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_150.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   150   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_150.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  150   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_150.txt

    # (/usr/bin/time -v ./case data/sars_1435K.fna 50    200   data/sars_1.txt)   &> peak_ram/casestudy_sars_50_200.txt   
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   200   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_200.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   200   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_200.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   200   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_200.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  200   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_200.txt

    # (/usr/bin/time -v ./case data/sars_1435K.fna 50    250   data/sars_1.txt)   &> peak_ram/casestudy_sars_50_250.txt   
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   250   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_250.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   250   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_250.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   250   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_250.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  250   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_250.txt

    # (/usr/bin/time -v ./case data/sars_1435K.fna 50    500   data/sars_1.txt)   &> peak_ram/casestudy_sars_50_500.txt   
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   500   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_500.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   500   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_500.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   500   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_500.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  500   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_500.txt 
    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200  300  data/sars_1.txt)   &> peak_ram/casestudy_sars_200_300.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200  350  data/sars_1.txt)   &> peak_ram/casestudy_sars_200_350.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200  400  data/sars_1.txt)   &> peak_ram/casestudy_sars_200_400.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200  450  data/sars_1.txt)   &> peak_ram/casestudy_sars_200_450.txt

    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  750   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_750.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1000  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1000.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1200  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1200.txt 
    
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  800   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_800.txt  
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  850   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_850.txt
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  900   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_900.txt 
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  950   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_950.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1000  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1000.txt
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1050  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1050.txt 
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1100  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1100.txt 
    (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1150  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1150.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1200  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1200.txt 
)