n, m = map(int, input().split(" "))
nn = list(map(int, input().split(" ")))
mm = list(map(int, input().split(" ")))

nn = list(sorted(nn, reverse = True))
mm = list(sorted(mm, reverse = True))
i = 0
a, b = 0, 0
while(True):
    if(nn[i] < mm[i]):
        b += 1
    else:
        a += 1
    print(nn[i], ' ',mm[i])
    i += 1
    if(i == n or i == m):
        break
print(a,' ', b)
