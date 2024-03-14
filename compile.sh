#!/usr/bin/bash

g++ -c -o wordinfo.o wordinfo.cpp -fPIC
g++ -shared -o wordinfo.so wordinfo.o
g++ -c -o wordinfo_cmd.o wordinfo_cmd.cpp
g++ -o wordinfo_cmd wordinfo_cmd.o -ldl

g++ -shared -o wordinfo_pybind.so -fPIC -std=c++11 -I/home/${USER}/.local/lib/python3.10/site-packages/pybind11/include wordinfo_pybind.cpp -I/usr/include/python3.10 -L. -Wl,-rpath='$ORIGIN' ./wordinfo.so -lpython3.10
