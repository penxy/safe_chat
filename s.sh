#!/bin/bash

function check(){
    [ $? -ne 0 ] && echo "make error"  && exit 1
    echo "make success"
}

cd build;
rm -rf *
cmake ..
make -j8
check

cd ..
./release/linux/bin/Client
