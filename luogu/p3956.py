import heapq

n, t = map(int, input().split())

# chess board
cb = [[0]*n for i in range(n)]
cost = [[1e9]*n for i in range(n)]

for i in range(t):
    x, y, v = map(int, input().split())
    x -= 1
    y -= 1
    v += 1
    cb[x][y] = v

dx = [-1, 0, 1, 0, -2, -1, 0, 1, 2, 1, 0, -1]
dy = [0, 1, 0, -1, 0, 1, 2, 1, 0, -1, -2, -1]

def bfs():
    pq = []
    heapq.heappush(pq, (0, 0, 0))
    cost[0][0] = 0
    while(len(pq)>0):
        c, x, y = heapq.heappop(pq)
        for i in range(len(dx)):
            nx, ny = x+dx[i], y+dy[i]
            if(nx<0 or nx>=n or ny<0 or ny>=n):
                continue
            new_c = c
            if(i >= 4):
                new_c += 2
            if(cb[nx][ny]==0):
                continue
            if(cb[nx][ny]!=cb[x][y]):
                new_c += 1
            if(cost[nx][ny] > new_c):
                cost[nx][ny] = new_c
                heapq.heappush(pq, (new_c, nx, ny))

bfs()

if(cb[n-1][n-1]==0):
    c1 = cost[n-2][n-1]+2
    c2 = cost[n-1][n-2]+2
    cost[n-1][n-1] = min(c1, c2)

if(cost[n-1][n-1] >= 1e9):
    cost[n-1][n-1] = -1

print(cost[n-1][n-1])
