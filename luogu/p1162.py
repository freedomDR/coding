from collections import deque

n = int(input())

s = [[0]*(n+2)]
for i in range(n):
    s.append(list(map(int, input().split())))
    s[-1].insert(0, 0)
    s[-1].append(0)
s.append([0]*(n+2))

vis = [[False]*(n+2) for i in range(n+2)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

q = deque()
q.append((0, 0))
vis[0][0] = True
while(len(q)>0):
    tmp = q.popleft()
    x, y = tmp[0], tmp[1]
    for i in range(len(dx)):
        xx, yy = x+dx[i], y+dy[i]
        if(xx<0 or xx>n+1 or yy<0 or yy>n+1):
            continue
        if(vis[xx][yy]==True or s[xx][yy] == 1):
            continue
        vis[xx][yy] = True
        q.append((xx, yy))

for i in range(1,n+1):
    for j in range(1, n+1):
        if(vis[i][j] == True or s[i][j]==1):
            print(s[i][j], end=' ')
        else:
            print(2, end=' ')
    print()
