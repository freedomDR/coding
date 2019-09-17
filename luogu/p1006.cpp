#include<bits/stdc++.h>
using namespace std;
int dp[110][55][55];
int n, m, matrix[55][55];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> matrix[i][j];
    for(int k = 1; k < m+n-1; k++)
    {
        for(int i = 0; i < m && i <= k; i++)
        {
            for(int j = i+1; j < m && j <= k; j++)
            {
                dp[k][i][j] = max(max(dp[k-1][i-1][j], dp[k-1][i][j-1]), max(dp[k-1][i-1][j-1], dp[k-1][i][j])) + matrix[k-i][i] + matrix[k-j][j];
            }
        }
    }
    cout << dp[n+m-2][m-2][m-1] << endl;
    return 0;
}
