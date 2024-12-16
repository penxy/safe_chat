# use it in Windows or Linux
import os
import sys
import shutil
from colorama import Fore
import subprocess
import platform

def func_check(msg, ret):
    if ret == 0:
        print(f"{Fore.GREEN} {msg} OK {Fore.RESET}")
    else:
        print(f"{Fore.RED} {msg} Error {Fore.RESET}")
        sys.exit(1)
def clean():
    if os.path.exists("./build") == True:
        shutil.rmtree("./build")
class Main_Windows:
    cmake="D:\\cmake\\cmake-3.31.0-rc2-windows-x86_64\\bin\\cmake.exe"
    def Compile(self):
        ret = os.system(f'{self.cmake} -S . -B ./build -G "MinGW Makefiles"')
        func_check("cmake", ret)
        ret = os.system("make -C ./build -j6")
        func_check("make", ret)
    def Run(self, app_name, conf_str = "", is_back = False):
        subprocess.run([f"release/{platform.system()}/bin/{app_name}", f"{conf_str}"])
class Main_Linux:
    cmake="cmake"
    def Compile(self):
        ret = os.system(f'{self.cmake} -S . -B ./build')
        func_check("cmake", ret)
        ret = os.system("make -C ./build -j6")
        func_check("make", ret)
    def Run(self, app_name, conf_str = "", is_back = False):
        subprocess.run([f"release/{platform.system()}/bin/{app_name}", f"{conf_str}"])
if __name__ == "__main__":
    if platform.system() == "Linux":
        F = Main_Linux()
        F.Compile()
        if len(sys.argv) == 2 and sys.argv[1] == "test":
            F.Run("test")
        else:
            F.Run("Client", f"-b{os.getcwd()}/Client")
    else:
        F = Main_Windows()
        F.Compile()
        if len(sys.argv) == 2 and sys.argv[1] == "test":
            F.Run("test")
        else:
            F.Run("Client.exe", f"-b{os.getcwd()}/Client")