import bisect
n = int(input())

arr = []
for i in range(n):
    a, b = map(int, input().split())
    arr.append((a, b))
arr.sort()
q = []
for v in arr:
    if(len(q) == 0 or v[1] > q[-1]):
        q.append(v[1])
    else:
        q[bisect.bisect_left(q, v[1])] = v[1]
    # print(q)
print(len(q))