# coding=utf-8

n, m = map(int, input().split())

cats = [list(map(int, input().split())) for _ in range(n)]
dogs = [list(map(int, input().split())) for _ in range(m)]

cats_count = [0]*n
for i in range(m):
    min_d = 1000000000
    min_index = -1
    for j in range(n):
        distance = (cats[j][0]-dogs[i][0])**2 + (cats[j][1]-dogs[i][1])**2
        if min_d > distance:
            min_d = distance
            min_index = j
    cats_count[min_index] += 1

ans = 0
for i in cats_count:
    if i == 1: ans += 1
print(ans)
