#!/usr/bin/env python
# -*- coding: utf-8 -*-

from collections import defaultdict
s = input()
count = defaultdict(int)
t = defaultdict(int)
max_len = 0
j = 1
for i, v in enumerate(s, 1):
    if count[v] == 0:
        count[v]+= 1
        max_len = max(max_len, i - j + 1)
    else:
        j = t[v]
    t[v] = i + 1
print(max_len)
