import sys

for x in sys.stdin:
    if int(x) == 0: break;
    print(1 if int(x) % 17 == 0 else 0)
