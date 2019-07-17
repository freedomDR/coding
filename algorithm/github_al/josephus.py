#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
妙，真妙
'''


def josephus(init_list, skip):
    skip -= 1
    idx = 0
    len_list = len(init_list)
    while len_list > 0:
        idx = (idx+skip)%len_list
        yield init_list.pop(idx)
        len_list -= 1

