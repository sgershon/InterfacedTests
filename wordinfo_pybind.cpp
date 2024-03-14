#include <pybind11/pybind11.h>
#include <pybind11/stl.h> // Include this for std::string conversion
#include "wordinfo.h"

namespace py = pybind11;

PYBIND11_MODULE(wordinfo_pybind, m) {
    py::class_<WordInfo>(m, "WordInfo")
        .def_readonly("length", &WordInfo::length)
        .def_readonly("original", &WordInfo::original)
        .def_readonly("uppercase", &WordInfo::uppercase)
        .def_readonly("lowercase", &WordInfo::lowercase);
    
    m.def("getWordInfo", &getWordInfo);
    m.def("generateRandomWord", &generateRandomWord);
}
