# coding=utf-8

n, k = map(int, input().split())

s = [[]for _ in range(n)]

for i in range(n):
    s[i] = input()

f = [[1 for d in range(n)] for _ in range(n)]
for i in range(n):
    for j in range(n):
        ssum = 0
        for t in range(j, min(j+k, n)):
            if s[i][t] == '.':
                ssum += 1
            else:
                break
        if ssum >= k:
            for t in range(k):
                f[i][j+t] = f[i][j+t] + 1
for i in range(n):
    for j in range(n):
        ssum = 0
        for t in range(j, min(n, j+k)):
            if s[t][i] == '.':
                ssum += 1
            else:
                break
        if ssum >= k:
            for t in range(k):
                f[j+t][i] += 1
ans, ans_x, ans_y = 0, 0, 0
for i in range(n):
    for j in range(n):
        if ans < f[i][j]:
            ans = f[i][j]
            ans_x = i+1
            ans_y = j+1

print(ans_x, ans_y)

