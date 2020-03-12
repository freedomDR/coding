#include<bits/stdc++.h>

using namespace std;

int dp[250][250], can[250][250], n, a[250];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        can[i][i] = 1;
        dp[i][i] = a[i];
    }
    int ans = 0;
    for(int len = 2; len <= n; len++)
    {
        for(int i = 1, j = i+len-1; j <= n; i++, j++)
        {
            for(int k = i; k <= j-1; k++)
            {
                if(can[i][k]&&can[k+1][j]&&dp[i][k]==dp[k+1][j])
                {
                    can[i][j] = 1;
                    dp[i][j] = max(dp[i][j], dp[i][k]+1);
                }
            }
            // cout << i << " " << j << " " << dp[i][j] << endl;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}