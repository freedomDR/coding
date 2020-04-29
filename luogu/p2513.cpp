#include<bits/stdc++.h>

using namespace std;

//dp[i][k] += dp[i-1][k-(kk)] (kk 0-min(k, i-1))
//dp[i][j] += dp[i-1][jj] (jj max(0,j-i+1)~j)
int n, k, sums, dp[1005][1005];
const int mod = 10000;
int main()
{
    cin >> n >> k;
    dp[1][0] = 1;
    for(int i = 2; i <= n; i++)
    {
        sums = 0;
        for(int j = 0; j <= k; j++)
        {
            sums = (sums+dp[i-1][j])%mod;
            dp[i][j] = sums;
            if(j >= i-1)
                sums = (sums-dp[i-1][j-i+1]+mod)%mod;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}