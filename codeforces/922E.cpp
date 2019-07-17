#include <bits/stdc++.h>

using namespace std;

int c[1005], cost[1005], k;
long long dp[10005], p, n, w, b, x;

int main()
{
    cin>>n>>w>>b>>x;
    for(int i = 0; i < n; i++) scanf("%d", &c[i]);
    for(int i = 0; i < n; i++) scanf("%d", &cost[i]);
    dp[0] = w;
    for(int i = 0; i < n; i++){
        for(int j = k; j >= 0; j--){
            p = dp[j];
            for(int l = 1; l <= c[i]; l++){
                p -= cost[i];
                if(p < 0) break;
                dp[j+l] = max(dp[j+l], p);
                k=max(k, j+l);
            }
        }
        for(int j = 1; j <= k; j++) dp[j] = min(dp[j]+x, w+b*j);
    }
    cout<<k<<endl;
    return 0;
}
