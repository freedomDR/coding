n = int(input())
k = int(input())
max_tmp = 0
sum_tmp = 0
min_k = 0
for i in range(n):
    tmp = int(input())
    max_tmp = max(max_tmp, tmp)
    sum_tmp += tmp
if sum_tmp + k <= max_tmp*n:
    min_k = max_tmp
else:
    min_k = max_tmp + (sum_tmp + k - max_tmp*n + n - 1)//n
print(min_k, max_tmp+k)

