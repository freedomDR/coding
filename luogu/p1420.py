n = int(input())
sz, pre = 0, -1
ans = 1
arr = list(map(int, input().split()))
for v in arr:
    if(v==pre+1):
        sz += 1
    else:
        sz = 1
    pre = v
    ans = max(ans, sz)
print(ans)