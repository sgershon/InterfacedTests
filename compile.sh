#!/usr/bin/bash

g++ -c -o wordinfo_sdk.o wordinfo_sdk.cpp -fPIC
g++ -shared -o wordinfo_sdk.so wordinfo_sdk.o
g++ -c -o wordinfo_cli.o wordinfo_cli.cpp
g++ -o wordinfo_cli wordinfo_cli.o -ldl

g++ -shared -o wordinfo_pybind.so -fPIC -std=c++11 -I/home/${USER}/.local/lib/python3.10/site-packages/pybind11/include wordinfo_pybind.cpp -I/usr/include/python3.10 -L. -Wl,-rpath='$ORIGIN' ./wordinfo_sdk.so -lpython3.10
