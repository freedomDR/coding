#include<bits/stdc++.h>

using namespace std;

int d[105][105], g[105][105];
const int inf = 1e8;
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i!=j) d[i][j]=g[i][j]=inf;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u][v] = g[v][u] = min(w, g[v][u]);
        d[u][v] = d[v][u] = min(w, d[v][u]);
    }
    int ans = inf;
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i < k; i++)
            for(int j = i+1; j < k; j++)
                ans = min(ans, g[i][k]+g[k][j]+d[i][j]);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]), d[j][i] = d[i][j];
    }
    if(ans == inf) cout << "No solution." << endl;
    else cout << ans << endl;
    return 0;
}