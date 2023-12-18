#!/usr/bin/python3
def magic_calculation(a, b):
    result = 0
    for k in range(1, 3):
        try:
            if k > a:
                raise Exception('Too far')
            result += a ** b / k
        except Exception:
            result = b + a
            break
    return result
