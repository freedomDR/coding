#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
s = list(input())
l, r = [0]*len(s), [0]*len(s)
for i in range(len(s)-1, -1, -1):
    if s[i] == 'G':
        if i == len(s)-1: r[i] = 1
        else: r[i] += r[i+1] + 1
for i in range(len(s)):
    if s[i] == 'G':
        if i == 0: l[i] = 1
        else: l[i] += l[i-1] + 1

ans = 0
for i in range(len(s)):
    if s[i] == 'S':
        tmp = 1
        if i == 0: tmp += r[i+1]
        elif i == len(s)-1: tmp += l[i-1]
        else: tmp += l[i-1]+r[i+1]
        ans = max(ans, tmp)
g_num = 0
for c in s: 
    if c == 'G': g_num += 1
ans = min(ans, g_num)
if g_num == n: ans = n
print(ans)

