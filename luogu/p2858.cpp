#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll dp[2005][2005];
int n, v[2005];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    dp[1][n] = 0;
    for(int len = n-1; len > 0; len--)
    {
        for(int i = 1, j = 1+len-1; j <= n; i++, j++)
        {
            dp[i][j] = max(dp[i-1][j]+1ll*(n-len)*v[i-1], 1ll*dp[i][j+1]+(n-len)*v[j+1]);
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i][i] += 1ll*n*v[i];
        ans = max(ans, dp[i][i]);
    }
    cout << ans << endl;
    return 0;
}