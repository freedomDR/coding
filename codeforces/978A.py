# coding=utf-8

n = int(input())
a = list(map(int, input().split()))
f = [0] * 1010
ans = []
for v in reversed(a):
    if f[v] == 0:
        ans.append(v)
    f[v] += 1
print(len(ans))
ans = reversed(ans)
print(*ans)
