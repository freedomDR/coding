#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
a = list(map(int, input().split()))
edges = [[] for i in range(n)]
for i in range(n-1):
    u, v = map(int, input().split())
    u-=1
    v-=1
    edges[u].append(v)
    edges[v].append(u)

sums = 0
suffix_n = [0]*n
def dfs1(u,h,pre = -1):
    global sums
    sums += a[u]*h
    suffix_n[u] = a[u]
    for v in edges[u]:
        if v == pre: continue
        dfs1(v, h+1, u)
        suffix_n[u]+=suffix_n[v]
dfs1(0,0)
ans = -1
def dfs2(u, pre = -1):
    global sums, ans
    ans = max(ans, sums)
    for v in edges[u]:
        if v == pre: continue
        sums -= suffix_n[v]
        suffix_n[u] -= suffix_n[v]
        sums += suffix_n[u]
        suffix_n[v] += suffix_n[u]
        dfs2(v,u)
        suffix_n[v] -= suffix_n[u]
        sums -= suffix_n[u]
        suffix_n[u] -= suffix_n[v]
        sums += suffix_n[v]
dfs2(0)
print(ans)

