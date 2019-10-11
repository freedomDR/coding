#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> g(n+1, vector<int>(m+2));
    vector<vector<int>> row(n+1, vector<int>(m+2));
    vector<vector<int>> colum(n+1, vector<int>(m+2));
    vector<vector<int>> dp(n+1, vector<int>(m+2));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(g[i][j] == 0)
            {
                row[i][j] = row[i][j-1]+1;
                colum[i][j] = colum[i-1][j]+1;
            }
        }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(g[i][j] == 0) continue;
            g[i][j] = min(g[i-1][j-1], min(row[i][j-1], colum[i-1][j]))+1;
            ans = max(ans, g[i][j]);
        }
    }
    dp.assign(n+1, vector<int>(m+2));
    row.assign(n+1, vector<int>(m+2));
    colum.assign(n+1, vector<int>(m+2));
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--)
        {
            if(g[i][j] == 0)
            {
                row[i][j] = row[i][j+1]+1;
                colum[i][j] = colum[i-1][j]+1;
            }
        }
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= 1; j--)
        {
            if(g[i][j] == 0) continue;
            g[i][j] = min(g[i-1][j+1], min(row[i][j+1], colum[i-1][j]))+1;
            ans = max(ans, g[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
