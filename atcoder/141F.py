# -*- coding: utf-8 -*-
N = int(input())
A = list(map(int, input().split()))

pre = [0]*len(A)
pre[0] = A[0]
aft = [0]*len(A)
aft[-1] = A[-1]
for pos, it in enumerate(A[1:], 1):
    pre[pos] = pre[pos-1]+it
for pos in range(len(A)-2, -1, -1):
    aft[pos] = aft[pos+1]+A[pos]
ans = 0;
print(pre)
print(aft)
for pos in range(len(A)-1):
    if(pos == 0):
        ans = max(ans, 0+(A[pos]^A[pos+1])+aft[pos+2])
    elif(pos == len(A)-2):
        ans = max(ans, pre[pos-1]+(A[pos]^A[pos+1])+0)
    else:
        ans = max(ans, pre[pos-1]+(A[pos]^A[pos+1])+aft[pos+2])
    print(ans)
print(ans)
