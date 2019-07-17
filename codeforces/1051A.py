# -*- coding: utf-8 -*-

t = int(input())
for ii in range(t):
    l, d, u = 0, 0, 0
    s = input()
    for tmp in list(s):
        if tmp.isnumeric():
            d += 1
        elif tmp.islower():
            l += 1
        elif tmp.isupper():
            u += 1
    if l == len(s):
        print('1A' + s[2:])
    elif d == len(s):
        print('aA' + s[2:])
    elif u == len(s):
        print('a1' + s[2:])
    elif l + d == len(s):
        ans = list(s)
        if l == 1:
            for i, v in enumerate(s, 0):
                if s[i].isnumeric():
                    ans[i] = 'A'
                    break
        elif d == 1:
            for i, v in enumerate(s, 0):
                if s[i].islower():
                    ans[i] = 'A'
                    break
        else:
            ans[0] = 'A'
        print(''.join(ans))
    elif l + u == len(s):
        ans = list(s)
        if l == 1:
            for i, v in enumerate(s, 0):
                if s[i].isupper():
                    ans[i] = '1'
                    break
        elif u == 1:
            for i, v in enumerate(s, 0):
                if s[i].islower():
                    ans[i] = '1'
                    break
        else:
            ans[0] = '1'
        print(''.join(ans))
    elif u + d == len(s):
        ans = list(s)
        if u == 1:
            for i, v in enumerate(s, 0):
                if s[i].isnumeric():
                    ans[i] = 'a'
                    break
        elif d == 1:
            for i, v in enumerate(s, 0):
                if s[i].isupper():
                    ans[i] = 'a'
                    break
        else:
            ans[0] = 'a'
        print(''.join(ans))
    else:
        print(s)
