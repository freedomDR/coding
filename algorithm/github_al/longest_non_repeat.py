#!/usr/bin/env python
# -*- coding: utf-8 -*-


def longest_non_repeat_v1(string):

    j = 0
    max_length = 0
    dict = {}
    for i in range(len(string)):
        if string[i] in dict:
            j = max(dict[string[i]], j)
        dict[string[i]] = i + 1
        max_length = max(max_length, i-j+1)
    return max_length

def longest_non_repeat_v2(string):
    pass

print(longest_non_repeat_v1('pwwkew'))
