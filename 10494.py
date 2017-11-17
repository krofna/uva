import sys

for x in sys.stdin:
    a, op, b = x.split()
    print(int(a) // int(b) if op == '/' else int(a) % int(b))
