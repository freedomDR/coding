#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
让数组每个数出现ｎ次
"""
from collections import defaultdict

def delete_nth(array, n):
    res = []
    count = defaultdict(int)

    for t in array:
        if count[i] < n:
            res.append(i)
            count[i] += 1
    return res
