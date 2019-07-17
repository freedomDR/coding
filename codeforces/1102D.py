#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
s = input()
nums = [0]*3
for v in s:
    nums[int(v)] += 1
s = list(s)
for i in range(n):
    if s[i] == "2" and nums[-1] > n//3:
        if nums[0]<n//3:
            s[i]="0"
            nums[0] += 1
            nums[-1] -= 1
        elif nums[1]<n//3:
            s[i]="1"
            nums[1] += 1
            nums[-1] -= 1
    elif s[i] == '1' and nums[1] > n//3:
        if nums[0]<n//3:
            s[i]='0'
            nums[0] += 1
            nums[1] -= 1
for i in range(n-1, -1, -1):
    if s[i]=='0' and nums[0] > n//3:
        if nums[2]<n//3:
            s[i] = '2'
            nums[2] += 1
            nums[0] -= 1
        elif nums[1]<n//3:
            s[i] = '1'
            nums[1] += 1
            nums[0] -= 1
    elif s[i]=='1'and nums[1]>n//3:
        if nums[2]<n//3:
            s[i]='2'
            nums[2]+=1
            nums[1]-=1
print(''.join(s))
