from collections import deque

n, t = map(int, input().split())

# chess board
cb = [[0]*n for i in range(n)]
cost = [[-1]*n for i in range(n)]

for i in range(t):
    x, y, v = map(int, input().split())
    x -= 1
    y -= 1
    v += 1
    cb[x][y] = v

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

cost[0][0] = 0
d = deque()
d.append((0, 0))

while(len(d)>0):
    x, y = d.popleft()
    for i in range(len(dx)):
        nx, ny = x+dx[i], y+dy[i]
        if(nx<0 or nx==n or ny<0 or ny==n):
            continue 
        if(cb[nx][ny]==cb[x][y] and cb[x][y]==0):
            continue 
        if(cb[nx][ny]==cb[x][y]):
            cost[nx][ny] = cost[x][y]
        elif(cb[nx][ny]==0):
            cost[nx][ny] = cost[x][y]+2
        else:
            cost[nx][ny] = cost[x][y]+1

print(cost[n-1][n-1])
