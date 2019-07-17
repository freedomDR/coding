# coding=utf-8

a = list(map(int, input().split()))

ans, n = 0, 14
for i in range(n):
    b = a[:]
    x, b[i] = b[i], 0
    for j in range(n):
        b[j] += x//n
    x %= n
    while x:
        i=(i+1)%n;b[i]+=1;x-=1
    ans = max(ans, sum(x for x in b if x&1 < 1))
print(ans)
