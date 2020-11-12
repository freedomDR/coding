#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random
import subprocess


def quick_sort(arr, lo, hi):
    if(lo>=hi): return 
    key = arr[lo];
    i, j = lo, hi
    while(i<j):
        while(i<j and arr[j]>key):j-=1
        if(i<j): arr[i], i = arr[j], i+1
        while(i<j and arr[i]<key):i+=1
        if(i<j): arr[j], j =arr[i], j-1
    arr[i]=key
    quick_sort(arr, lo, i-1)
    quick_sort(arr, i+1, hi)
    return arr

arr = random.sample(range(100), 10)
print("origin arr is {}".format(arr));
print("sort arr is {}".format(quick_sort(arr, 0, len(arr)-1)));
