n = int(input())

a = [0]*1001
f = [0]*1001
for i in range(1, 1001):
    for j in range(i+i, 1001, i):
        a[j] += i
for i in range(1, 1001):
    for j in range(n, i-1, -1):
        f[j] = max(f[j], f[j-i]+a[i])
print(f[n])
        