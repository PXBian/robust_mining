# robust_mining

Pre-install:
1. bash pre-install.sh

Execute RPM-ESA:
1. g++ -O3 -DNDEBUG -I ./libsdsl/include/ -L ./libsdsl/lib/ runs.hpp intervaltree.hpp main_ESA.cpp -o esa -lsdsl -ldivsufsort -ldivsufsort64
2. ./esa <text_file> <\tau> <\k> 

Execute RPM-ST:
1. make all
2. ./main <text_file> <\tau> <\k> 
