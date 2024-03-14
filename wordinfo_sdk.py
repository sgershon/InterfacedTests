from collections import namedtuple
import wordinfo_pybind

Word = namedtuple('Word', ['original', 'length', 'uppercase', 'lowercase'])

def random_word():
    word = wordinfo_pybind.generateRandomWord()
    return word

def word_data(word):
    info = wordinfo_pybind.getWordInfo(word)
    data = Word(info.original, info.length, info.uppercase, info.lowercase)
    return data

if __name__ == "__main__":
    pass
