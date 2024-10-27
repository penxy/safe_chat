import os
import shutil

cmake="/home/pxy/download/cmake_3_30/cmake-3.30.5-linux-x86_64/bin/cmake"

os.chdir("./build")
files = os.listdir()
for file in files:
    if os.path.isfile(file):
        os.remove(file)
    elif os.path.isdir(file):
        shutil.rmtree(file)

os.system(f"{cmake} .. && make -j6")
os.chdir("..")
os.system("./bin/Demo")


