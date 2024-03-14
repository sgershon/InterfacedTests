
# Dual Interface for Test

Method to create an intermediate layer that lets us cover multiple interfaces with single tests.

## Files

### CPP:
* wordinfo.h - SDK Headers
* wordinfo.cpp - SDK Implementation
* wordinfo_cmd.cpp - Command line that exercises SDK

### Python and CPP-Python binding:
* wordinfo_pybind.cpp - File with binding info
* wordinfo_sdk.py - Wraps the SDK
* wordinfo_cmd.py - Wraps the command line
* wi_tests.py - all tests, able to run with one or the other

### Other files:
* README.md - this

## Compiling and Deployment

To compile the SDK and executable:

```bash
g++ -c -o wordinfo.o wordinfo.cpp -fPIC
g++ -shared -o wordinfo.so wordinfo.o
g++ -c -o wordinfo_cmd.o wordinfo_cmd.cpp
g++ -o wordinfo_cmd wordinfo_cmd.o -ldl
```

To bind the CPP SDK to Python:

```bash
sudo apt-get install python3.10-dev
pip install pybind11

g++ -shared -o wordinfo_pybind.so -fPIC -std=c++11 -I<PATH_TO_PYBIND_INCLUDES> wordinfo_pybind.cpp -I<PATH_TO_PYTHON_INCLUDES> -L. -Wl,-rpath='$ORIGIN' <PATH_TO_WORDINFO_SO> -lpython3.10
```

(For example, in my system, paths look like `g++ -shared -o wordinfo_pybind.so -fPIC -std=c++11 -I/home/USERNAME/.local/lib/python3.10/site-packages/pybind11/include wordinfo_pybind.cpp -I/usr/include/python3.10 -L. -Wl,-rpath='$ORIGIN' /home/USERNAME/Projects/ctypes_test/pybind11/wordinfo.so -lpython3.10`)

Once compiled, run tests with:
```bash
python wi_tests.py
```


## Features

- Tests are identical for both interfaces
-- Tests can run 
- Changes in SDK require modifications only to wrapper, not to all tests
- Changes in CLI require modifications only to wrapper, not to all tests

## Demo

Insert gif or link to demo
