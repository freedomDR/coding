import math

n = int(input())

x1, y1, x2, y2 = map(float, input().split())

point = []
used = [False]*n
r = [0.0]*n

for i in range(n):
    x, y = map(float, input().split())
    point.append((x, y))

max_v = 0.0


def calDistance(i, j):
    return math.sqrt((point[i][0]-point[j][0]) ** 2 + (point[i][1]-point[j][1]) ** 2)


def findMax(i):
    d1 = min(abs(point[i][0]-x1), abs(point[i][0]-x2))
    d2 = min(abs(point[i][1]-y1), abs(point[i][1]-y2))
    d = min(d1, d2)
    for j in range(n):
        if(j != i and used[j] == True):
            d = min(d, max(calDistance(i, j)-r[j], 0.0))
    return d


def dfs(p, sums):
    global max_v
    if(p >= n):
        max_v = max(max_v, sums)
        return
    for i in range(n):
        if(used[i] == True):
            continue
        used[i] = True
        r[i] = findMax(i)
        dfs(p+1, sums+r[i]*r[i]*math.pi)
        used[i] = False


dfs(0, 0.0)

ans = abs(x2-x1)*abs(y1-y2)-max_v
print(int(ans+0.5))
