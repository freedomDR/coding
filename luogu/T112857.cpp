#include<bits/stdc++.h>

using namespace std;

int n, m, k, dis[205][205], dp[5005], e[205][205];
void floyd()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = e[i][j];
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]), dis[j][i]=dis[i][j];
}
int main()
{
    memset(e, 0x3f, sizeof e);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int a, b, w; cin >> a >> b >> w;
        e[a][b] = min(e[a][b], w);
        e[b][a] = e[a][b];
    }
    floyd();
    vector<pair<int, int>> pick(k+1);
    for(int i = 1; i <= k; i++)
    {
        cin >> pick[i].first >> pick[i].second;
    }
    sort(pick.begin()+1, pick.end());
    pick[0].second = 1;
    int ans = 0;
    for(int i = 1; i <= k; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            int need = pick[i].first - pick[j].first, a = pick[i].second, b = pick[j].second;
            if(a==b||need>=dis[a][b]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}