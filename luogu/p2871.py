n, m = map(int, input().split())
v, w = [0]*(n+1), [0]*(n+1)
for i in range(n):
    v[i+1], w[i+1] = map(int, input().split())

f = [0] * (m+1)
for i in range(1, n+1):
    for j in range(m, v[i]-1, -1):
        f[j] = max(f[j], f[j-v[i]]+w[i])
print(f[m])