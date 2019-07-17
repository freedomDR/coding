# coding=utf-8

n = int(input())
s = str(input())
zero = 0
for i in range(n):
    if s[i] == '0':
        zero += 1
if zero != n:
    print('1'+'0'*zero)
else:
    print('0'*zero)

