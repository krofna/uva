import sys

fi = [-1 for x in range(5001)]
fi[0] = 0
fi[1] = 1
for i in range(2, 5001):
    fi[i] = fi[i - 1] + fi[i - 2]

for x in list(map(int, sys.stdin)):
    print('The Fibonacci number for', x, 'is', fi[x])
