#!/usr/bin/env python
# -*- coding: utf-8 -*-
arr = [6,5,4,2,1,8,3]
def qsort(l, r):
    global arr
    if l >= r: return
    first, last, key = l, r, arr[l]
    while first < last:
        while first < last and arr[last] >= key: last -= 1
        arr[first] = arr[last]
        while first < last and arr[first] <= key: first += 1
        arr[last] = arr[first]
    arr[first] = key
    print(arr)
    if first == l: return
    qsort(l, first)
    qsort(first+1, r)

qsort(0, len(arr)-1)
print(arr)
