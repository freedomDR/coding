#!/usr/bin/env python
# -*- coding: utf-8 -*-
def garage(init_arr, final_arr):
    init_arr = init_arr[::]
    seqs = 0
    seq = []
    while init_arr != final_arr:
        zero = init_arr.index(0)
        if zero != final_arr.index(0):
            tmp_val = final_arr[zero]
            tmp_pos = init_arr.index(tmp_val)
            init_arr[zero], init_arr[tmp_pos] = init_arr[tmp_pos], init_arr[zero]
        else:
            for i, v in enumerate(init_arr):
                if v != final_arr[i]:
                    init_arr[zero], init_arr[i] = init_arr[i], init_arr[zero]
                    break
        seqs += 1
        seq.append(init_arr[::])
    return seqs, seq

