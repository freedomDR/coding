#!/usr/bin/env python
# -*- coding: utf-8 -*-

s = input()
ans = 0

def dfs(i, count):
    global ans
    if i >= len(s):
        if i == len(s) and count == 3: ans += 1
        return
    if i+1 < len(s): dfs(i+1, count+1)
    else: return
    if s[i+1] == '0': return
    dfs(i+2, count + 1)
    if i+3 < len(s) and s[i+3] == '0' and s[i+2] == '0': return
    else: dfs(i+3, count + 1)

dfs(0, 0)
if s[0] != '0':
    dfs(1, 0)
    if s[1] != 0 and s[2] != 0:
        dfs(2, 0)
print(ans)
