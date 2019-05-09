#!/usr/bin/env python
# -*- coding: utf-8 -*-
class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        t = set()
        for s in emails:
            s2 = s.split('@')[1]
            s1 = s.split('@')[0]
            s1 = s1.split('+')[0]
            string = s1.replace('.', '') +'@'+ s2
            t.add(string)
        #print(t)
        return len(t)
