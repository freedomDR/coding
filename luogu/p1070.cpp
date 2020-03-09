#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1050;

int n, m, p, q[MAXN][MAXN], l[MAXN], r[MAXN], f[MAXN][MAXN], loc[MAXN][MAXN];
int cost[MAXN], dp[MAXN], add[MAXN];

int getid(int i, int j)
{
    return ((j-i)%n+n)%n;
}

int main()
{
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> f[j][i];
            f[j][i] += f[j-1][i-1];
        }
    }
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    for(int i = 0; i < n; i++)
    {
        q[i][++r[i]] = -cost[i];
        l[i]++;
    }
    memset(dp, ~0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int id = getid(i, j);
            while(l[id]<=r[id]&&loc[id][l[id]]+p<i) l[id]++;
            if(!j) add[id] += f[i][n];
            if(l[id]<=r[id])
                dp[i] = max(dp[i], q[id][l[id]]+f[i][j]+add[id]);            
        }
        for(int j = 0; j < n; j++)
        {
            int id = getid(i, j);
            int tmp = dp[i]-f[i][j]-add[id]-cost[j];
            while(l[id]<=r[id]&&q[id][r[id]]<=tmp)
            {
                r[id]--;
            }
            loc[id][++r[id]] = i;
            q[id][r[id]] = tmp;
        }
    }
    cout << dp[m] << endl;
    return 0;
}