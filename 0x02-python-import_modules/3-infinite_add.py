#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    result = 0
    for argmnt in sys.argv:
        if argmnt != sys.argv[0]:
            result += int(argmnt)
    print(result)
