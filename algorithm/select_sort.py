#!/usr/bin/env python
# -*- coding: utf-8 -*-
import random

def select_sort(arr):
    if(len(arr) == 0): return arr;
    for i in range(len(arr)):
        min_pos = i
        for j in range(i+1, len(arr)):
            if(arr[j]<arr[min_pos]): min_pos = j
        arr[i], arr[min_pos] = arr[min_pos], arr[i]
    return arr

arr = random.sample(range(100), 10)
print("origin arr is {}".format(arr));
print("sort arr is {}".format(select_sort(arr)));

