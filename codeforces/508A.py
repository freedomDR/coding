#!/usr/bin/env python
# -*- coding: utf-8 -*-

n, k = map(int, input().split())
s = input()
t = [0]*26
for i,v in enumerate(s):
    t[ord(v) - ord('A')] += 1

print(min(t[:k])*k)
