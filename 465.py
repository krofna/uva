import sys

for l in sys.stdin:
    x, c, y = l.split()
    x = int(x)
    y = int(y)
    print(l[:-1])
    if x >= 2**31:
        print('first number too big')
    if y >= 2**31:
        print('second number too big')
    if (c == '+' and x + y >= 2**31) or (c == '*' and x * y >= 2**31):
        print('result too big')
