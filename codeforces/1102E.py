#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
a = list(map(int, input().split()))
ans = 0
end = {}
for p, v in enumerate(a):
    end[v] = p
visit = [False]*n
mod = 998244353
for i in range(n):
    if not visit[i]:
        if ans == 0: ans = 1
        else: ans = ans*2%mod
        last = end[a[i]]
        j = i
        while j <= last:
            visit[j] = True
            last = max(last, end[a[j]])
            j+=1
print(ans)
    
