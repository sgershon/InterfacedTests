import argparse

import wordinfo_sdk
import wordinfo_cli

parser = argparse.ArgumentParser(description='Process command line arguments.')
parser.add_argument('--sdk', action='store_true', help='Use SDK. If flag is absent, will test via CLI.')
parser.add_argument('--repeats', type=int, default=20, help='Number of tets to run (default: 20).')
args = parser.parse_args()
wordinfo = wordinfo_sdk if args.sdk else wordinfo_cli

def test():
    for _ in range(1, args.repeats+1):
        word = wordinfo.random_word()
        data = wordinfo.word_data(word)

        def veredict(res):
            return "✓" if res else "𐄂"
        
        results = {
            "Length": data.length == len(word),
            "Upper": data.uppercase == word.upper(),
            "Lower": data.lowercase == word.lower()
            }

        print(f"Test {_:3} ({data.original:25}) - ", end="")
        for i, (test, result) in enumerate(results.items()):
            print(f"{test}: {veredict(result)} ", end="")
        print()

if __name__ == "__main__":
    test()
