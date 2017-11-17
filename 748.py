import sys

for l in sys.stdin:
    a, b = l.split()
    i = (5 - a.index('.')) * int(b)
    a = a.replace('.', '')
    c = str(int(a)**int(b))
    z = len(c) - i
    if z >= 0:
        print(c[0:z].lstrip('0') + '.' + c[z:].rstrip('0'))
    else:
        print('.' + '0' * -z + c.rstrip('0'))
