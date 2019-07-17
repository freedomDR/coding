#!/usr/bin/env python
# -*- coding: utf-8 -*-
import random

def merge(left, right):
    ans = []
    while(len(left)>0 and len(right)>0):
        if(left[0] > right[0]):
            ans.append(right.pop(0))
        else:
            ans.append(left.pop(0))
    if(len(left)==0): ans += right
    else: ans += left
    return ans

def merge_sort(arr, lo, hi):
    if(lo>=hi): return [arr[lo]]
    mid = lo+(hi-lo)//2
    left = merge_sort(arr, lo, mid)
    right = merge_sort(arr, mid+1, hi)
    return merge(left, right)

arr = random.sample(range(100), 10)
print("origin arr is {}".format(arr));
print("sort arr is {}".format(merge_sort(arr, 0, len(arr)-1)));

