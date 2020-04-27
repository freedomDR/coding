m, n = map(int, input().split())
a = []
for i in range(n):
    v = int(input())
    a.append(v)

f = [0] * (m+1)
for v in a:
    for j in range(m, v-1, -1):
        f[j] = max(f[j], f[j-v]+v)
print(f[m])