# coding=utf-8
s = str(input())


links = 0
for i in range(len(s)):
    if s[i] == '-':
        links += 1

pearls = len(s) - links
if pearls == 0:
    print('YES')
elif links%pearls == 0:
    print('YES')
else:
    print('NO')

