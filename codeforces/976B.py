# coding=utf-8
import math

n, m, k = map(int, input().split())

if k < n:
    print(k+1, 1)
else:
    k -= n-1
    x = n - k//(m-1)
    k %= m-1
    if k == 0:
        x += 1
        if x%2 == 0:
            y = m
        else:
            y = 2
    else:
        if x%2 == 1:
            y = m-k+1
        else:
            y = 1+k
    print(x, y)

