// wordinfo.h
#ifndef WORDINFO_H
#define WORDINFO_H

#include <string>

struct WordInfo {
    int length;
    std::string original;
    std::string uppercase;
    std::string lowercase;
};

extern "C" {
    WordInfo getWordInfo(const std::string& word);
    std::string generateRandomWord();
}

#endif // WORDINFO_H
