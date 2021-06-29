from collections import deque

n, m, x, y = map(int, input().split())
x -= 1
y -= 1

ans = [[-1]*m for i in range(n)]
d = deque()
d.append((x, y))
ans[x][y] = 0

dx = [-2, -1, 1, 2, 2, 1, -1, -2]
dy = [1, 2, 2, 1, -1, -2, -2, -1]

while(len(d)>0):
    tmp = d.popleft()
    x, y = tmp[0], tmp[1]
    for pos in range(len(dx)):
        nx, ny = x+dx[pos], y+dy[pos]
        if(nx<0 or nx>=n or ny<0 or ny>=m or ans[nx][ny]!=-1):
            continue
        ans[nx][ny] = ans[x][y]+1
        d.append((nx, ny))

for line in ans:
    for v in line:
        print("{:<5}".format(v), end='')
    print()