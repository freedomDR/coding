#include<bits/stdc++.h>

using namespace std;

const int maxn = 1505;
int g[maxn][maxn], ans, n, m, gg[maxn][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m; 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {    
            cin >> g[i][j];
            if(i%2 == j%2) g[i][j] ^= 1;
            gg[i][j] = g[i][j]^1;
        }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(g[i][j]) g[i][j] = min(g[i-1][j-1], min(g[i][j-1], g[i-1][j]))+1;
            if(gg[i][j]) gg[i][j] = min(gg[i-1][j-1], min(gg[i][j-1], gg[i-1][j]))+1;
            ans = max(ans, max(g[i][j], gg[i][j]));
        }
    }
    cout << ans << endl;
    return 0;
}