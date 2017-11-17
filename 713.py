n = int(input())
for x in range(0, n):
    print(str(sum(map(int, map(lambda x:x[::-1], input().split()))))[::-1].lstrip('0'))
