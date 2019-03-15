#!/Users/jye/.brew/bin/python3/

import sys

def hash_(s):
    val = 85206151
    for i in s:
        val ^= ord(i) * 85206151
        val += 85206151
    return val & 0xffffffff

print("{:x}".format(hash_(sys.argv[1])))
