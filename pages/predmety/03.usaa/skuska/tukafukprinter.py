def printstring(string):
    v = 0
    for c in string:
        i = ord(c)
        while v < i:
            print("INK ",end="")
            v += 1
        while v > i:
            print("DEK ",end="")
            v -= 1
        print("KUK")

def program():
    print("TUK")
    printstring("USAA\n")
    print("FUK")

if __name__ == "__main__":
    program()
