#include<bits/stdc++.h>

using namespace std;

int dp[10010], t, n, m, p[110][110];

int main()
{
    cin >> t >> n >> m;
    for(int i = 1; i <= t; i++)
    {
        for(int j = 1; j <= n; j++)
            cin >> p[i][j];
    }
    int ans = m;
    for(int i = 1; i < t; i++)
    {
        memset(dp, 0, sizeof(dp));
        dp[ans] = ans;
        for(int j = 1; j <= n; j++)
        {
            for(int k = ans; k >= p[i][j]; k--)
            {
                dp[k-p[i][j]] = max(dp[k-p[i][j]], dp[k]+(p[i+1][j]-p[i][j]));
            }
        }
        for(int j = 0, r = ans; j <= r; j++)
        {
            ans = max(ans, dp[j]);
        }
    }
    cout << ans << endl;
    return 0; 
}