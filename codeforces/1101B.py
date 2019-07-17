#!/usr/bin/env python
# -*- coding: utf-8 -*-

s = input()
ans = -1
left = 0
right = len(s) - 1
lok = 1
while left < len(s):
    if s[left] == '[':
        lok = 2
        left += 1
    elif s[left] == ':' and lok == 2:
        break
    else:
        left += 1
rok = 1
while right >= 0:
    if s[right] == ']':
        rok = 2
        right -= 1
    elif s[right] == ':' and rok == 2:
        break
    else:
        right -= 1
if rok == lok and rok == 2 and left < right:
    ans = 4
    while left < right:
        if s[left] == '|': ans += 1
        left += 1
else: ans = -1
print(ans)
