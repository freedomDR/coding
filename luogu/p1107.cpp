#include<bits/stdc++.h>

using namespace std;

int n, h, d, g[2005][2005], maxp[2005], dp[2005][2005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> h >> d;
    for(int i = 1; i <= n; i++)
    {
        int ns; cin >> ns;
        for(int j = 0; j < ns; j++)
        {
            int pos; cin >> pos;
            g[pos][i]++;
        }
    }
    for(int i = h; i >= 1; i--)
    {
        int tmp = 0;
        for(int j = 1; j <= n; j++)
        {
            if(i+d<2005) dp[i][j] = max(dp[i+1][j]+g[i][j], dp[i+d][maxp[i+d]]+g[i][j]);
            else dp[i][j] = dp[i+1][j]+g[i][j];
            if(dp[i][tmp] < dp[i][j]) {tmp = j;}
        }
        maxp[i] = tmp;
        // cout << dp[i][tmp] << " " << tmp << endl;
    }
    cout << dp[1][maxp[1]] << endl;
    return 0;
}