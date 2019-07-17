#!/usr/bin/env python
# -*- coding: utf-8 -*-

n, x, y = map(int, input().split())
a = list(map(int, input().split()))

if x > y:
    print(n)
else:
    tmp = 0
    for v in a:
        if v <= x:
            tmp += 1
    if tmp%2 == 0:
        print(tmp//2)
    else:
        print(tmp//2 + 1)
