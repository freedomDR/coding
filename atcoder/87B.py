a = int(input())
b = int(input())
c = int(input())
x = int(input())

ans, mid = 0, 0
for i in range(a+1):
    for j in range(b+1):
        for k in range(c+1):
            mid = i*500 + j * 100 + k * 50
            if mid == x:
                ans += 1
print(ans)

