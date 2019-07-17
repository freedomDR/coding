n, x = map(int, input().split())
m = []
for i in range(n):
    a,b = map(int, input().split())
    m.append([a,b])
m.append([x,0])
m = list(sorted(m, key = lambda i:i[0]))
for i in range(1,n+1):
    m[i][1] += m[i-1][1]

ans = 100000000
for i in range(n+1):
    if(m[i][0] >= x):
        ans = min(m[i][0]-m[i][1], ans)
ans = min(ans, x)
print(ans)
    
