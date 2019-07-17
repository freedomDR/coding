# coding=utf-8

a = list(map(int, input().split()))
n = int(input())
ans = sum(a) + max(a)*((2**n)-1)  
print(ans)
