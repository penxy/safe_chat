#!/bin/bash

function func_check(){
    [ $? -ne 0 ] && echo "make error"  && exit 1
    echo "make success"
}
OS=$(uname)

cd build;
rm -rf *
cmake ..
make -j8
func_check

cd ..
./release/$OS/bin/Client --base $PWD --path $PWD/release/$OS/bin --confile $PWD/release/$OS/etc/client.conf
