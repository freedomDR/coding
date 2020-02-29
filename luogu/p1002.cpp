#include <bits/stdc++.h>
using namespace std;

long long dp[25][25];
int n, m, x, y;
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

const int inf = 0x7f7f7f7f;

int main()
{
    cin >> n >> m >> x >> y;
    for(int i = 0; i < 8; i++)
    {
        int xx = x+dx[i], yy = y+dy[i];
        if(xx >= 0 && xx <= n && yy >= 0 && yy <= m)
            dp[xx][yy] = -1;
    }
    dp[0][0] = 1;
    dp[x][y] = -1;
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            if(dp[i][j] == -1) continue;
            else if(i == 0 && j == 0) continue;
            else if(i == 0) dp[i][j] = dp[i][j-1];
            else if(j == 0) dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = (dp[i-1][j]==-1?0:dp[i-1][j]) + (dp[i][j-1]==-1?0:dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
