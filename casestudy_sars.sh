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




    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   110   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_110.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   120   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_120.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   124   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_124.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   126   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_126.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 100   130   data/sars_1.txt)   &> peak_ram/casestudy_sars_100_130.txt  
    
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   210   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_210.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   220   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_220.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   230   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_230.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   240   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_240.txt 




    # (/usr/bin/time -v ./case data/sars_1435K.fna 300   220   data/sars_1.txt)   &> peak_ram/casestudy_sars_300_220.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 300   240   data/sars_1.txt)   &> peak_ram/casestudy_sars_300_240.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 300   260   data/sars_1.txt)   &> peak_ram/casestudy_sars_300_260.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 300   280   data/sars_1.txt)   &> peak_ram/casestudy_sars_300_280.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 300   300   data/sars_1.txt)   &> peak_ram/casestudy_sars_300_300.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 300   320   data/sars_1.txt)   &> peak_ram/casestudy_sars_300_320.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 300   340   data/sars_1.txt)   &> peak_ram/casestudy_sars_300_340.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 300   360   data/sars_1.txt)   &> peak_ram/casestudy_sars_300_360.txt


    # (/usr/bin/time -v ./case data/sars_1435K.fna 400   100   data/sars_1.txt)   &> peak_ram/casestudy_sars_400_100.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 400   150   data/sars_1.txt)   &> peak_ram/casestudy_sars_400_150.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 400   200   data/sars_1.txt)   &> peak_ram/casestudy_sars_400_200.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 400   250   data/sars_1.txt)   &> peak_ram/casestudy_sars_400_250.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 400   260   data/sars_1.txt)   &> peak_ram/casestudy_sars_400_260.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 400   320   data/sars_1.txt)   &> peak_ram/casestudy_sars_400_320.txt


    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   300   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_300.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   350   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_350.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   380   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_380.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   400   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_400.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   420   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_420.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   440   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_440.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   460   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_460.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   480   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_480.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   520   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_520.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   540   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_540.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   560   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_560.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   580   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_580.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   600   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_600.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   620   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_620.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   640   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_640.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   660   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_660.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   680   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_680.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   700   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_700.txt  

    # (/usr/bin/time -v ./case data/sars_1435K.fna 800   680   data/sars_1.txt)   &> peak_ram/casestudy_sars_800_680.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 800   720   data/sars_1.txt)   &> peak_ram/casestudy_sars_800_720.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 800   760   data/sars_1.txt)   &> peak_ram/casestudy_sars_800_760.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 800   800   data/sars_1.txt)   &> peak_ram/casestudy_sars_800_800.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 800   840   data/sars_1.txt)   &> peak_ram/casestudy_sars_800_840.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 800   880   data/sars_1.txt)   &> peak_ram/casestudy_sars_800_880.txt

    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  750   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_750.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  800   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_800.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  850   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_850.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  900   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_900.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  950   data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_950.txt  
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1000  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1000.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1050  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1050.txt 

    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1100  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1100.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1150  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1150.txt 
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1200  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1200.txt 

    # (/usr/bin/time -v ./case data/sars_1435K.fna 600   600   data/sars_1.txt)   &> peak_ram/casestudy_sars_600_600.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 700   700   data/sars_1.txt)   &> peak_ram/casestudy_sars_700_700.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 800   800   data/sars_1.txt)   &> peak_ram/casestudy_sars_800_800.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 900   900   data/sars_1.txt)   &> peak_ram/casestudy_sars_900_900.txt

    # (/usr/bin/time -v ./case data/sars_1435K.fna 150   150   data/sars_1.txt)   &> peak_ram/casestudy_sars_150_150.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 200   200   data/sars_1.txt)   &> peak_ram/casestudy_sars_200_200.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 500   500   data/sars_1.txt)   &> peak_ram/casestudy_sars_500_500.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 1000  1000  data/sars_1.txt)   &> peak_ram/casestudy_sars_1000_1000.txt

    # (/usr/bin/time -v ./case data/sars_1435K.fna 250   250   data/sars_1.txt)   &> peak_ram/casestudy_sars_250_250.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 450   450   data/sars_1.txt)   &> peak_ram/casestudy_sars_450_450.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 750   750   data/sars_1.txt)   &> peak_ram/casestudy_sars_750_750.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 350   350   data/sars_1.txt)   &> peak_ram/casestudy_sars_350_350.txt
    # (/usr/bin/time -v ./case data/sars_1435K.fna 550   550   data/sars_1.txt)   &> peak_ram/casestudy_sars_550_550.txt

    
    (/usr/bin/time -v ./case data/sars_1435K.fna 650   650   data/sars_1.txt)   &> peak_ram/casestudy_sars_650_650.txt
    (/usr/bin/time -v ./case data/sars_1435K.fna 850   850   data/sars_1.txt)   &> peak_ram/casestudy_sars_850_850.txt
    (/usr/bin/time -v ./case data/sars_1435K.fna 400   400   data/sars_1.txt)   &> peak_ram/casestudy_sars_400_400.txt


)