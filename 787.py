import sys

for l in sys.stdin:
    mi = ma = ans = 1
    xma = -999999
    for x in map(int, l.split()):
        if x == -999999: break
        if x > 0:
            ma *= x
            mi = min(mi * x, 1)
        elif x == 0:
            ma = mi = 1
        else:
            tmp = ma
            ma = max(mi * x, 1)
            mi = tmp * x
        ans = max(ans, ma)
        xma = max(xma, x)
    print(ans if ans != 1 else xma)
            
