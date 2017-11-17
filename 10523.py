import sys

def f(n, a, i):
    return a * (i + f(n, a, i + 1)) if i <= n else 0

for x in sys.stdin:
    n, a = map(int, x.split())
    print(f(n, a, 1))
