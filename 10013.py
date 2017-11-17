n = int(input())

for x in range(0, n):
    if x != 0:
        print()
    input()
    m = int(input())
    s = z = ''
    for y in range(0, m):
        a, b = input().split()
        s += a
        z += b
    print(int(s) + int(z))
