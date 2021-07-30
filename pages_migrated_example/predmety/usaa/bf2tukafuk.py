import sys
lng = {
    "+": "INK",
    "-": "DEK",
    "<": "GLEK",
    ">": "BREK",
    "[": "[",
    "]": "]",
    ".": "KUK",
    ",": "PUK",
}

print("TUK")
for l in sys.stdin:
    lc = 0
    for c in l:
        if c in lng:
            print(lng[c], end= " ")
            lc += 1
        if lc > 20:
            print("")
            lc = 0
print("FUK")

