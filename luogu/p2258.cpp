#include<bits/stdc++.h>

using namespace std;

int g[20][20], n, m, r, c, choice[20], ans = 0x3f3f3f3f;
int cols[20], tt[20][20], dp[20][20];
//dp[i][j]=min(dp[k][j-1]+cols[i]+tt[k][i])
void calc()
{
    memset(dp, 0x3f, sizeof dp);
    memset(cols, 0, sizeof cols);
    memset(tt, 0, sizeof tt);
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= r-1; j++)
        {
            cols[i] += abs(g[choice[j]][i]-g[choice[j+1]][i]);  
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = i+1; j <= m; j++)
        {
            for(int k = 1; k <= r; k++)
            {
                tt[i][j] += abs(g[choice[k]][i]-g[choice[k]][j]);
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        dp[i][1] = cols[i];
        for(int j = 2; j <= min(c, i); j++)
        {
            for(int k = j-1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j-1]+cols[i]+tt[k][i]);
            }
        }
        ans = min(ans, dp[i][c]);
        /* cout << ans << endl; */
    }
}

void dfs(int cur, int p)
{
    if(p == r+1)
    {
        calc();
        return;
    }
    for(int i = cur; i <= n; i++)
    {
        choice[p] = i;
        dfs(i+1, p+1);
        choice[p] = 0;
    }
}

int main()
{
    cin >> n >> m >> r >> c;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
        }
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
