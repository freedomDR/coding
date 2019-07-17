# coding=utf-8

n, k = map(int, input().split())

ans = [list('.'*n) for _ in range(4)]
if k%2 == 0:
    for i in range(k//2):
        ans[1][i+1], ans[2][i+1] = '#', '#'
else:
    for i in range((k%(n-2))//2):
        ans[1][i+1], ans[1][n-1-1-i] = '#', '#'
    if k//(n-2) == 1:
        ans[2] = list('#'*n)
        ans[2][0], ans[2][n-1] = '.', '.'
    else:
        ans[1][n//2] = '#'
        
print('YES')
for i in range(4):
    print(''.join(ans[i]))
