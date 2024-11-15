#! /bin/sh

tar -xvf sdsl-lite.tar.gz
cd sdsl-lite
./install.sh "$(pwd)"/libsdsl
mv libsdsl/ ..


# gunzip sdsl-lite-master.zip
# cd sdsl-lite-master
# ./install.sh "$(pwd)"/libsdsl
# mv libsdsl/ ..