#!/usr/bin/env python
# -*- coding: utf-8 -*-

n = int(input())
s = input()
pos = 0
for i in range(n):
    print(s[pos], end='')
    pos += i+1
    if pos >= n: break

