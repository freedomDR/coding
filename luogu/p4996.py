

if(__name__=='__main__'):
    m = int(input())
    f1, f2 = 0, 1
    m1, m2 = 0, 1
    cnt = 1
    for i in range(10000000):
        cnt+=1 
        f1, f2 = f2, f2+f1
        f1 %= m
        f2 %= m 
        if(f1 == 0 and f2 == 1):
            print(cnt-1)
            break