#include <bits/stdc++.h>

using namespace std;

int judge(int i)
{
    if(i <= 3){
        return 2;
    }
    int mid = int(sqrt(i));
    for(int j = 2; j <= mid; j++){
        if(i%j == 0)
            return 1;
    }
    return 2;
}

int main()
{
    int k,m,n,prime[1000001],ans;
    prime[1] = 1;
    for(int i = 2; i < 1000001; i++){
        if(prime[i] != 0) continue;
        prime[i] = judge(i);
        for(int j = i*2; j < 1000001; j *= 2){
            prime[j] = 1;
        }
    }
    scanf("%d",&k);
    while(k--){
        ans = 0;
        scanf("%d %d", &m, &n);
        for(int i = m; i <= n; i++){
            if(prime[i] == 2)
                ans++;
        }
        printf("%d\n", ans);
    }
    printf("END\n");
    return 0;
}
