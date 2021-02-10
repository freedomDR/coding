

if(__name__ == "__main__"):
    a1, a2, n = map(int, input().split(' '))

    d = a2-a1
    an = a1+(n-1)*d
    ret = (a1+an)*n//2
    print(ret)