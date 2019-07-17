#!/usr/bin/env python
# -*- coding: utf-8 -*-

M = int(input())
arr = [list(map(int, input().split())) for i in range(M)]
ans = 0
f = [[0]*M for i in range(M)]

def dfs(i, j):
    if i == M or i == -1 or j == M or j == -1:
        return
    f[i][j] = 1
    if arr[i][j] == 0:
        return
    if i+1 != M and f[i+1][j] == 0: dfs(i+1, j)
    if i-1 != -1 and f[i-1][j] == 0: dfs(i-1, j)
    if j+1 != M and f[i][j+1] == 0: dfs(i, j+1)
    if j-1 != -1 and f[i][j-1] == 0: dfs(i, j-1)

for ii in range(M):
    for jj in range(M):
        if f[ii][jj] == 0 and arr[ii][jj] == 1:
            dfs(ii, jj)
            ans += 1
        f[ii][jj] = 1
print(ans)

