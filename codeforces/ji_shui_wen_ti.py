#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = list(map(int, input().split()))

def slove1():
    ans, tmp = 0, -1
    lmax,rmax = [0]*len(n), [0]*len(n)
    for i in range(1, len(n)):
        tmp = max(tmp, n[i-1])
        lmax[i] = tmp
    tmp = -1
    for i in range(len(n)-2, -1, -1):
        tmp = max(tmp, n[i+1])
        rmax[i] = tmp
    for i in range(len(n)):
        if lmax[i] > n[i] and rmax[i] > n[i]: ans += min(lmax[i], rmax[i]) - n[i]
    return ans
def slove2():
    l, r = 0, len(n) - 1
    lmax,rmax,ans = n[0],n[-1],0
    while l < r:
        if lmax < rmax:
            l += 1
            if n[l] > lmax: lmax = n[l]
            else: ans += lmax - n[l]
        else:
            r -= 1
            if n[r] > rmax: rmax = n[r]
            else: ans += rmax -n[r]
    return ans

print(slove1())
print(slove2())
