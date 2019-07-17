#!/usr/bin/env python
# -*- coding: utf-8 -*-


def max_ones_index(arr):
    n = len(arr)

    max_count = 0
    max_index = 0
    prev_zero = -1
    prev_prev_zero = -1
    for i in range(n):
        if arr[i] == 0:
            if i - prev_prev_zero > max_count:
                max_count = i - prev_prev_zero
                max_index = prev_zero
            prev_prev_zero = prev_zero
            prev_zero = i
    if n - prev_prev_zero > n:
        max_index = prev_zero
    return max_index

# print(max_ones_index([1, 1,1, 1, 0, 1, 1]))
