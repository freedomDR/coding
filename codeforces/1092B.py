#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
a = list(map(int, input().split()))
ans = 0
a.sort()
for i in range(1, n, 2):
    ans += a[i]-a[i-1]
print(ans)
