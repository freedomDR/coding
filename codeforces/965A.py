# coding=utf-8
import math
k, n, s, p = map(int, input().split())

res = math.ceil(k*math.ceil(n/s)/p)

print(res)

