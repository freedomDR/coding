#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
a = list(map(int, input().split()))

a = sorted(a)
ans = min(a[-2]-a[0], a[-1]-a[1])
print(ans)
