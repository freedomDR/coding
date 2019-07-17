# coding=utf-8

n = int(input())
s = list(str(input()))
ans, sum_x = 0, 0
for v in s:
    if v == 'x':
        sum_x += 1
    else:
        if sum_x > 2: ans += sum_x - 2
        sum_x = 0
if sum_x > 2: ans += sum_x - 2
print(ans)

