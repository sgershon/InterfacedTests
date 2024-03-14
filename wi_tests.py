# import wordinfo_sdk as wordinfo
import wordinfo_cli as wordinfo

for _ in range(20):
    word = wordinfo.random_word()
    data = wordinfo.word_data(word)

    def veredict(res):
        return "✓" if res else "𐄂"
    
    results = (data.length == len(word), data.uppercase == word.upper(), data.lowercase == word.lower())
    print(f"Test {_:2} ({data.original:25}) - ", end="")
    for i, test in enumerate(["Length", "Upper", "Lower"]):
        print(f"{test}: {veredict(results[i])} ", end="")
    print()

