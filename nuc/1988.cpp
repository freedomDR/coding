#include <bits/stdc++.h>

using namespace std;

int pre[10001];

int main()
{
    int prime[10000], len = 0;
    for(int i = 0; i <= 10000; i++)
        pre[i] = 1;
    pre[0] = 0;
    pre[1] = 0;
    pre[2] = 1;
    for(int i = 2; i <= 10000; i++){
        if(pre[i] == 0)
            continue;
        prime[len++] = i;
        for(int j = i+i; j <= 10000; j+=i){
            pre[j] = 0;
        }
    }
    int t, n, a, b, c;
    long long ans;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>n;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                int res = n - prime[i] - prime[j];
                if(res <= 0 || pre[res] == 0) continue;
                if(ans <  (long long)prime[i]*prime[j]*res){
                    a = min(prime[i], min(prime[j], res));
                    c = max(prime[i], max(prime[j], res));
                    b = n - a - c;
                    ans = a*b*c;
                }
            }
        }
        if(ans == 0)
            printf("-1\n");
        else{
            printf("%d %d %d %lld\n", a,b,c,ans);
        }
    }
    return 0;
}
