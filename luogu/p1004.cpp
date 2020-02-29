#include<bits/stdc++.h>

using namespace std;

int g[10][10], n;
int dp[10][10];
int main()
{
    cin >> n;
    while(1)
    {
        int x, y, v;
        cin >> x >> y >> v;
        if(x == 0 && y == 0 && v == 0) break;
        g[x][y] = v;
    }
    dp[1][1] = g[1][1];
    for(int step = 1; step < 2*n-1; step++)
    {
        for(int i = n; i >= 1; i--)
        {
            for(int ii = n; ii >= 1; ii--)
            {
                int j = 1+step-(i-1), jj = 1+step-(ii-1);
                if(j<=0||j>n||jj<=0||jj>n) continue;
                dp[i][ii] = max(dp[i][ii], dp[i][ii]);
                dp[i][ii] = max(dp[i][ii], dp[i-1][ii]);
                dp[i][ii] = max(dp[i][ii], dp[i][ii-1]);
                dp[i][ii] = max(dp[i][ii], dp[i-1][ii-1]);
                dp[i][ii] += g[i][j] + g[ii][jj];
                if(i == ii) dp[i][ii] -= g[i][j];
                //cout << step << " " << i << " " << ii << " " << dp[step][i][ii] << endl;
            }
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
