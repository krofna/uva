import sys

a = [0 for x in range(1001)]

def f(n):
    if n == 0: return 1
    if a[n] != 0: return a[n]
    a[n] = 2 * f(n - 1) + f(n - 2) + f(n - 3) if n > 0 else 0
    return a[n]

for x in sys.stdin:
    print(f(int(x)))
