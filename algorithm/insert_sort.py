#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random

def insert_sort(arr):
    if(len(arr) == 0): return arr;
    for i in range(1, len(arr)-1):
        for j in range(i-1, -1, -1):
            if(arr[j] > arr[j+1]): arr[j], arr[j+1] = arr[j+1], arr[j]
            else: break
    return arr

arr = random.sample(range(100), 10)
print("origin arr is {}".format(arr));
print("sort arr is {}".format(insert_sort(arr)));


