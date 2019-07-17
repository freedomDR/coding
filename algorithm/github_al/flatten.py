#!/usr/bin/env python
# -*- coding: utf-8 -*-
from collections import Iterable


def flatten(input_arr, output_arr = None):
    if output_arr is None:
        output_arr = []
    for t in input_arr:
        if isinstance(t, Iterable):
            flatten(t, output_arr)
        else:
            output_arr.append(t)
    return output_arr

def flatten_iter(iterable):
    for t in iterable:
        if isinstance(t, Iterable):
            yield from flatten_iter(t)
        else:
            yield t
