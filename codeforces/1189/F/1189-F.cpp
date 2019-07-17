#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int m = a[n-1]-a[0];
    long long ans = 0;
    for(int d = 1; d*(k-1) <= m; d++){
        int dp[n+1][k+1];
        for(int i = 0 ; i <= n; i++)
            for(int j = 0; j <= k; j++)
                dp[i][j] = 0;
        for(int i = 0; i <= n; i++)
            dp[i][1] = i;
        for(int i = 2; i <= k; i++) {
            int p = 0;
            for(int j = 1; j <= n; j++) {
                while(a[j-1]-a[p] >= d) p++;
                dp[j][i] = (dp[j-1][i] + dp[p][i-1])%mod;
            }
        }
        ans = (ans + dp[n][k])%mod;
        /* if(dp[n][k] != 0) */ 
        /* cout << "d = " << d << " ans = " << dp[n][k] << endl; */
    }
    cout << ans << endl;
    return 0;
}
