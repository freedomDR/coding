#!/usr/bin/env python
# -*- coding: utf-8 -*-

t = int(input())
for j in range(t):
    n = int(input())
    data = []
    for i in range(n):
        l,r = map(int, input().split())
        data.append((l, r, i))
    data.sort(key=lambda x:x[0])
    rmax = data[0][1]
    ok = -1
    for i in range(n):
        if data[i][0] > rmax:
           ok = rmax
           break
        rmax = max(rmax, data[i][1])
    if ok == -1:
        print('-1')
    else:
        data.sort(key=lambda x:x[2])
        for i in range(n):
            if data[i][1] <= ok:
                print('1', end=' ')
            else:
                print('2', end=' ')
        print()
