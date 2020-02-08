#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2005;
int l[MAXN][MAXN], r[MAXN][MAXN], up[MAXN][MAXN], n, m, g[MAXN][MAXN];


int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> g[i][j];
            l[i][j] = r[i][j] = j;
            up[i][j] = 1;
        }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 2; j <= m; j++)
        {
            if(g[i][j] != g[i][j-1])
                l[i][j] = l[i][j-1];
        }
        for(int j = m-1; j > 0; j--)
        {
            if(g[i][j] != g[i][j+1])
                r[i][j] = r[i][j+1];
        }
    }
    int ans1=0, ans2=0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(i > 1 && g[i][j] != g[i-1][j])
            {
                up[i][j] = up[i-1][j]+1;
                l[i][j] = max(l[i][j], l[i-1][j]);
                r[i][j] = min(r[i][j], r[i-1][j]);
            }
            int a = r[i][j]-l[i][j]+1, b = up[i][j];
            ans1 = max(ans1, min(a*a, b*b));
            ans2 = max(ans2, a*b);
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
