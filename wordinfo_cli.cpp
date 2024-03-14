#include "wordinfo.h"
#include <iostream>
#include <dlfcn.h>

int main(int argc, char *argv[]) {
    void* handle = dlopen("./wordinfo_sdk.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error: Failed to load library: " << dlerror() << std::endl;
        return 1;
    }

    WordInfo (*getWordInfo)(const std::string&);
    getWordInfo = reinterpret_cast<WordInfo (*)(const std::string&)>(dlsym(handle, "getWordInfo"));

    std::string word;
    if (argc > 1) {
        word = argv[1];

        WordInfo info = getWordInfo(word);
        std::cout << "Original: " << info.original << std::endl;
        std::cout << "Length: " << info.length << std::endl;
        std::cout << "Uppercase: " << info.uppercase << std::endl;
        std::cout << "Lowercase: " << info.lowercase << std::endl;

    } else {
        auto generateRandomWord = reinterpret_cast<std::string (*)()>(dlsym(handle, "generateRandomWord"));
        if (!generateRandomWord) {
            std::cerr << "Error: Couldn't find function generateRandomWord in the library." << std::endl;
            dlclose(handle);
            return 1;
        }
        word = generateRandomWord();

        std::cout << word << std::endl;
    }

    dlclose(handle);
    return 0;
}
