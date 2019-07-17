#!/usr/bin/env python
# -*- coding: utf-8 -*-

test_data = [12,5,8,10,2,16,259,1]

def merge_sort_not_recursion(data):
    step = 1
    while step <= len(data)//2:
        for i in range(0, len(data), step*2):
            res = []
            left = data[i:min(i+step, len(data))]
            right = data[min(i+step, len(data)-1):min(i+2*step, len(data))]
            while left and right:
                if left[0] < right[0]: res.append(left.pop(0))
                else: res.append(right.pop(0))
            if left: res += left
            if right: res += right
            data[i:i+len(res)] = res
        step += step
    return data

def merge(left, right):
    res = []
    while left and right:
        if left[0] < right[0]:
            res.append(left.pop(0))
        else:
            res.append(right.pop(0))
    if left:
        res += left
    if right:
        res += right
    return res

def merge_sort(data):
    if len(data) <= 1: return data
    mid = len(data)//2
    left, right = data[:mid], data[mid:]
    left, right = merge_sort(left), merge_sort(right)
    return merge(left, right)

print(test_data)
print('递归', merge_sort(test_data))
print('非递归', merge_sort_not_recursion(test_data))

