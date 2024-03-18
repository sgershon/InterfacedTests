
# Dual Interface for Test

Method to create an intermediate layer that lets us cover multiple interfaces with single tests.

## Files

### CPP:
* `wordinfo.h` - SDK Headers
* `wordinfo.cpp` - SDK Implementation
* `wordinfo_cmd.cpp` - Command line that exercises SDK

### Python and CPP-Python binding:
* `wordinfo_pybind.cpp` - File with binding info
* `wordinfo_api.py` - Wraps the SDK
* `wordinfo_cmd.py` - Wraps the command line
* `wi_tests.py` - Sample of a test able to run seamlessly with one wrapper or the other

### Other files:
* `compile.sh` - compiles c++ and binding. Pay attention pybind requires exact paths.
* `.gitignore` - git ignore
* `README.md` - this file 🙃

![image](https://github.com/sgershon/InterfacedTests/assets/10831143/25ead45c-bb8f-472b-83fc-1173014218da)

## Compiling and Deployment

To compile the SDK and executable:

```bash
g++ -c -o wordinfo_sdk.o wordinfo_sdk.cpp -fPIC
g++ -shared -o wordinfo_sdk.so wordinfo_sdk.o
g++ -c -o wordinfo_cli.o wordinfo_cli.cpp
g++ -o wordinfo_cli wordinfo_cli.o -ldl
```

To bind the CPP SDK to Python:

```bash
sudo apt-get install python3.10-dev
pip install pybind11

g++ -shared -o wordinfo_pybind.so -fPIC -std=c++11 -I<PATH_TO_PYBIND_INCLUDES> wordinfo_pybind.cpp -I<PATH_TO_PYTHON_INCLUDES> -L. -Wl,-rpath='$ORIGIN' <PATH_TO_WORDINFO_SO> -lpython3.10
```

(For example, in my system, paths look like `g++ -shared -o wordinfo_pybind.so -fPIC -std=c++11 -I/home/${USER}/.local/lib/python3.10/site-packages/pybind11/include wordinfo_pybind.cpp -I/usr/include/python3.10 -L. -Wl,-rpath='$ORIGIN' ./wordinfo.so -lpython3.10`)

Once compiled, run tests with:
```bash
# Tests interface via CLI by default:
python wi_tests.py

# To switch the interface to SDK:
python wi_tests.py --sdk

# Select the amount of tests to run with:
python wi_tests.py --sdk --repeat 50
```

## Features

- Tests are identical for both interfaces
-- Tests may run much faster when system calls are avoided
- Changes in SDK require modifications only to wrapper, not to all tests
- Changes in CLI require modifications only to wrapper, not to all tests

## Demo

The sample test `wi_tests.py` generates a word (a random string, really) with the wordinfo feature, and then runs the same word over wordinfo to get data about the string.  
Note that the same test runs with the same flow via SDK or CLI.  
Note the difference in speed when run in one or the other.  

[![asciicast](https://asciinema.org/a/C23FovFzQHUv9Gzmzt79VtuXX.svg)](https://asciinema.org/a/C23FovFzQHUv9Gzmzt79VtuXX)
