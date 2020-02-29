#include<bits/stdc++.h>
using namespace std;
int dp[55][55];
int n, m, matrix[55][55];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> matrix[i][j];
    for(int k = 1; k < m+n-1; k++)
    {
        for(int i = m; i > 0; i--)
        {
            for(int j = m; j > 0; j--)
            {
                int ii = 1+(k-i+1),jj = 1+(k-j+1);
                if(ii<=0||ii>n||jj<=0||jj>n) continue;
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), max(dp[i-1][j-1], dp[i][j])) + matrix[ii][i] + matrix[jj][j];
                if(i == j) dp[i][j] -= matrix[ii][i];
            }
        }
    }
    cout << dp[m][m] << endl;
    return 0;
}
