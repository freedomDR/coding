# -*- coding: utf-8 -*-
from math import gcd

l, r = map(int, input().split(' '))
ans = []
sum_ = (r-l+1)//2
area = [0]*(r-l+1)
ll = l - 1
while sum_ != 0:
    ll += 1
    if ll == r+1: break
    if area[ll-l] == 1: continue
    for i in range(ll-l+1, len(area)):
        rr = l+i
        if area[i] == 1: continue
        if gcd(ll, rr) == 1:
            ans.append((ll, rr))
            area[rr - l] = 1
            area[ll - l] = 1
            sum_ -= 1
            break
    area[ll - l] = 1
if sum_ == 0:
    print('YES')
    for t in ans:
        print(t[0], t[1])
else:
    print('NO')
