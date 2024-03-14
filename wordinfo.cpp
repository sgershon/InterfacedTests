// wordinfo.cpp
#include "wordinfo.h"
#include <random>
#include <algorithm>

WordInfo getWordInfo(const std::string& word) {
    WordInfo info;
    info.length = word.length();
    info.original = word;
    std::transform(word.begin(), word.end(), std::back_inserter(info.uppercase), ::toupper);
    std::transform(word.begin(), word.end(), std::back_inserter(info.lowercase), ::tolower);
    return info;
}

std::string generateRandomWord() {
    std::string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, letters.length() - 1);
    std::string randomWord;
    std::uniform_int_distribution<> lenDis(5, 25); // random length between 5 and 10
    int length = lenDis(gen);
    for (int i = 0; i < length; ++i) {
        randomWord += letters[dis(gen)]; // corrected selection of random letter
    }
    return randomWord;
}
