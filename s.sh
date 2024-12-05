#!/bin/bash
set -eu -o pipefail

cmake="/home/pxy/download/cmake_3_30/cmake-3.30.5-linux-x86_64/bin/cmake"
__OS__=$(uname)

function func_check(){
    [ $? -ne 0 ] && echo -e "\e[31m$1 error\e[0m"  && exit 1
    echo -e "\e[32m$1 success\e[0m"
}

[ ! -e "build" ] && mkdir build
$cmake -S . -B ./build
func_check "cmake"
make -C ./build -j6
func_check "make"

./release/$__OS__/bin/Client --base $PWD/release/$__OS__/ --qss=$PWD/release/$__OS__/etc/Qss
