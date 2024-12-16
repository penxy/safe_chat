#!/usr/bin/python3
import os
import sys
import shutil
from colorama import Fore

__OS__='Linux'
def func_check(str_op):
        ret = os.popen("echo $?").read()
        ret = ret.strip("\n")
        if ret == "0":
            print(Fore.GREEN + f"{str_op} OK")
        else:
            print(Fore.RED + f"{str_op} error")
            sys,exit(1)
class Main:
    def clean():
        if os.path.exists("./build") == True:
            shutil.rmtree("./build")
    def Compile(self):
        os.system("cmake -S . -B ./build")
        func_check("cmake")
        os.system("make -C ./build -j6")
        func_check("make")
    def Run(self, app_name, conf_str, is_back = False):
        print(Fore.WHITE)                       # set white color for print 10.25
        if is_back == False:
            os.system(f"./release/{__OS__}/bin/{app_name} {conf_str}")
        else:
            os.system(f"./release/{__OS__}/bin/{app_name} {conf_str} &")
if __name__ == "__main__":
    F = Main()
    F.Compile()
    F.Run("Client", f"--base {os.getcwd()}/release/{__OS__}")