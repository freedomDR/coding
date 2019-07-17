# coding=utf-8

n = int(input())
s = list(map(int, input().split()))
for i in range(1, n):
    s[i] += s[i-1]

ans = 0
s = sorted(s)
i = 0
while True:
    mid = 0
    for j in range(i+1, n):
        if s[j] == s[i]:
            mid += 1
            ans += mid
        else:
            break
    if s[i] == 0:
        ans += mid+1
    i += mid
    i += 1
    if i >= n:
        break
print(ans)
