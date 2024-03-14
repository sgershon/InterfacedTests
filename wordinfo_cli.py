from collections import namedtuple
import subprocess
from wordinfo_sdk import Word

cli = "./wordinfo_cmd"

def random_word():
    result = subprocess.run(cli, capture_output=True, text=True)
    result = result.stdout.strip()
    return result

def word_data(word):
    result = subprocess.run([cli, word], capture_output=True, text=True)
    result =  result.stdout.strip()

    original = ""
    upper = ""
    lower = ""

    properties = {}
    for line in result.split("\n"):
        property_name, value = line.split(': ', 1)
        properties[property_name] = value

    data = Word(properties["Original"], int(properties["Length"]),
                properties["Uppercase"], properties["Lowercase"])

    return data

if __name__ == "__main__":
    pass
