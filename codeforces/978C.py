# coding=utf-8

n, m =map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

for i in range(1, n):
    a[i] += a[i-1]

j = 0
for i in range(m):
    if b[i] > a[j]:
        while True:
            if b[i] <= a[j]: break
            j += 1
    if j == 0: print(1, b[i])
    else: print(j+1, b[i] - a[j-1])
