#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++) 
        {
            if(a[i] == j) dp[i][j] = dp[i-1][j] + 1;
            if(a[i] > j) dp[i][j] = dp[i-1][j];
            if(a[i] < j) dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i]];
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
