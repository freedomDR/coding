#!/usr/bin/env python
# -*- coding: utf-8 -*-

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    ans = ''
    for i in range(k):
        ans += chr(97+i)*(n//k)
    if n%k: ans += chr(97+k-1)*(n%k)
    print(ans)
