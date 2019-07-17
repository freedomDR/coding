#!/usr/bin/env python
# -*- coding: utf-8 -*-

q = int(input())
for t in range(q):
    n, m, k = map(int, input().split())
    if n > k or m > k:
        print('-1')
    else:
        print(k - (k - n)%2 - (k - m)%2)
