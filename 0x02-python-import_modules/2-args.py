#!/usr/bin/python3
if __name__ == "__main__":
    import sys
    k = len(sys.argv) - 1

    if k == 0:
        print("{} arguments.".format(k))
    elif i == 1:
        print("{} argument:".format(k))
    else:
        print("{} arguments:".format(k))

    if k >= 1:
        k = 0
        for arg in sys.argv:
            if k != 0:
                print("{}: {}".format(k, arg))
            k += 1
