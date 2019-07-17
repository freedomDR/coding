#!/usr/bin/env python
# -*- coding: utf-8 -*-

class Node:
    def __init__(self, k):
        self._label = k
        self._left = None
        self._right = None

    @property
    def left(self):
        return self._left
    @left.setter
    def left(self, l):
        self._left = l
    @property
    def right(self):
        return self._right
    @right.setter
    def right(self, r):
        self._right = r

if __name__ == '__main__':
    tree = Node(1)
    tree.left = Node(2)
    tree.right = Node(3)
    print(tree.left)
    print(tree.right)
