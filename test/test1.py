ca = [3,5,7,2,8,8,15,3]
co = [1,0,1,0,1,0,1,0]
n = 3
suf = [0]*len(ca)
pre = [0]*len(ca)
sums = [0]*len(ca)
for i in range(len(ca)):
    if(i != 0):
        suf[i] = suf[i-1]
        sums[i] = sums[i-1]
    if(co[i] == 0):
        suf[i] += ca[i]
    sums[i] += ca[i]
for i in range(len(ca)-1, -1, -1):
    if(i != len(ca)-1):
        pre[i] = pre[i+1]
    if(co[i] == 0):
        pre[i] += ca[i]
ans = sums[n-1]+pre[n]
pre.append(0)
for i in range(n, len(ca)):
    ans = max(ans, sums[i]-sums[i-n]+suf[i-n]+pre[i+1])
print(ans)