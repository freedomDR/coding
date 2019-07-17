#!/usr/bin/env python
# -*- coding: utf-8 -*-

from collections import defaultdict
n, k = map(int, input().split())
a = list(map(int, input().split()))
ok = True
nums = defaultdict(int)
for item in a:
    nums[item]+=1
    if nums[item] == k+1: 
        ok = False;break
if not ok:
    print('NO')
else:
    print('YES')
    value = 1
    ans = [0]*n
    for v in nums.keys():
        for pos, item in enumerate(a):
            if item == v:
                ans[pos] = value
                value %= k
                value += 1
    for v in ans:
        print(v, end=' ')
        

