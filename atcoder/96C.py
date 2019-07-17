# coding=utf-8

n, m = map(int, input().split())

s = [ list(str(input())) for _ in range(n) ]
add = [[1, 0],[-1, 0],[0, 1],[0, -1]]
ans = 'Yes'
for i in range(n):
    for j in range(m):
        if s[i][j] == '.': continue
        mid = False
        for k in range(4):
            ii = i + add[k][0]
            jj = j + add[k][1]
            if ii >= 0 and jj < m and ii < n and jj >= 0:
                if s[ii][jj] == '#': mid = True
        if not mid: ans = 'No';break
print(ans)
