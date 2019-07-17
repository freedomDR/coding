# coding=utf-8

n = int(input())
s = set(map(frozenset, input().split()))
print(len(s))
