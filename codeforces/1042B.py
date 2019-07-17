from collections import defaultdict

n = int(input())
juices = defaultdict(int)
for i in range(n):
    price, tmp = map(str, input().split())
    price = int(price)
    tmp = list(tmp)
    tmp.sort()
    tmp = ''.join(tmp)
    if juices[tmp] == 0:
        juices[tmp] = price
    else:
        juices[tmp] = min(juices[tmp], price)

ans = 1000000
juices = sorted(juices.items(), key=lambda x:x[1])

for k1, v1 in juices:
    if k1 == 'ABC':
        ans = min(ans, v1)
        continue
    for k2, v2 in juices:
        tmp2 = set(list(k1) + list(k2))
        tmp2 = list(tmp2)
        tmp2.sort()
        if ''.join(tmp2) == 'ABC':
            ans = min(ans, v2+v1)
            continue
        for k3, v3 in juices:
            tmp3 = set(list(k1) + list(k2) + list(k3))
            tmp3 = list(tmp3)
            tmp3.sort()
            if ''.join(tmp3) == 'ABC':
                ans = min(ans, v1+v2+v3)

if ans == 1000000:
    ans = -1
print(ans)
