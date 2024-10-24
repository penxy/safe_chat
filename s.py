import os
import sys
import shutil
from colorama import Fore

def func_check(str_op):
    ret = os.popen("echo $?").read()
    ret = ret.strip("\n")
    
    if str_os == "Linux":        
        if ret == "0":
            print(Fore.GREEN + f"{str_op} OK")
        else:
            print(Fore.RED + f"{str_op} error")
            sys,exit(1)
    else:
        if ret == "True":
            print(Fore.GREEN + f"{str_op} OK")
        else:
            print(Fore.RED + f"{str_op} error")
            sys.exit(1)
def set_arch():
    global str_os

    str_os = os.popen("uname").readline()
    str_os = str_os[0: -1]
def set_cmake():
    global cmake

    if str_os == "Linux":
        cmake = "/home/pxy/download/cmake_3_30/cmake-3.30.5-linux-x86_64/bin/cmake"
    elif str_os == "Window":
        cmake = "cmake -G \"MinGW Makefiles\""
    else:
        print(Fore.RED + "Unknow OS")
        sys.exit(-1)
def del_all_files():
    if os.path.exists("./build") == False:
        os.mkdir("./build")
    os.chdir("./build")
    
    files = os.listdir(os.getcwd())
    for file in files:
        if os.path.isfile(file):
            os.remove(file)
        else:
            shutil.rmtree(file)


set_arch()
set_cmake()
del_all_files()

os.system(f"{cmake} ..")
func_check("cmake")
os.system("make -j6")
func_check("make")
os.chdir("..")