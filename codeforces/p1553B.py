t = int(input())
for i in range(t):
    s1 = input()
    s2 = input()
    ans = False
    for i in range(len(s1)):
        if(ans == True):
            break
        for r in range(i, len(s1)):
            if(s1[i:r] != s2[:r-i] or ans == True):
                break
            p1 = r
            p2 = r-i
            while(True):
                if(p1==-1):
                    break
                if(s1[p1]!=s2[p2]):
                    break
                if(p2 == len(s2)-1):
                    ans = True
                    break
                p1-=1
                p2+=1
    if(ans == True):
        print("YES")
    else:
        print("NO")
            
            