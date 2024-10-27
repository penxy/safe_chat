#!/bin/bash

cmake="/home/pxy/download/cmake_3_30/cmake-3.30.5-linux-x86_64/bin/cmake"

function func_check(){
    [ $? -ne 0 ] && echo -e "\e[31m$1 error\e[0m"  && exit 1
    echo -e "\e[32m$1 success\e[0m"
}
OS=$(uname)

[ ! -e "build" ] && mkdir build
cd build && rm -rf *
$cmake ..
func_check "cmake"
make -j8
func_check "make"

cd ..
./release/$OS/bin/Client --base $PWD --path $PWD/release/$OS/bin --confile $PWD/release/$OS/etc/client.conf
# ./release/$OS/bin/GUI
