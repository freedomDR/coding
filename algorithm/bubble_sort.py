#!/usr/bin/env python
# -*- coding: utf-8 -*-
import random

def bubble_sort(arr):
    if(len(arr) == 0): return arr;
    for end in range(len(arr), 0, -1):
        is_sorting = True
        for j in range(1, end):
            if(arr[j] < arr[j-1]): 
                is_sorting = False
                arr[j], arr[j-1] = arr[j-1], arr[j]
        if(is_sorting): break;
    return arr

arr = random.sample(range(100), 10)
print("origin arr is {}".format(arr));
print("sort arr is {}".format(bubble_sort(arr)));

