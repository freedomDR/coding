#include<bits/stdc++.h>

using namespace std;

int n, m, startX, startY, endX, endY, t;
int dp[105][105][16];
char mx[105][105];

int main()
{
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> mx[i][j];
    cin >> startX >> startY >> endX >> endY;
    dp[startX][startY][0] = 1;
    for(int k = 1; k <= t; k++)
    {
        for(int i = 1; i <= n ; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(mx[i][j] == '*') continue;
                if(mx[i-1][j] != '*') dp[i][j][k] += dp[i-1][j][k-1];
                if(mx[i][j-1] != '*') dp[i][j][k] += dp[i][j-1][k-1];
                if(mx[i+1][j] != '*') dp[i][j][k] += dp[i+1][j][k-1];
                if(mx[i][j+1] != '*') dp[i][j][k] += dp[i][j+1][k-1];
            }
        }
    }
    cout << dp[endX][endY][t] << endl;
    return 0;
}