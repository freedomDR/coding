#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1)), g(n+1, vector<int>(m+1));
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == 1) dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
