# coding=utf-8

x1, x2, x3 = map(int, input().split())

d1 = x3 - x1
d2 = x3 - x2

if d1 >= 0 and d2 >= 0:
    print(max(d1, d2))
elif d1 <= 0 and d2 <= 0:
    print(max(-d1, -d2))
else:
    d = abs(x2-x1) + min(abs(d1), abs(d2))
    print(d)
