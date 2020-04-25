#include<bits/stdc++.h>

using namespace std;

int f[110][110], g[110][110], n, m, pre[110][110];

void print(int i, int p)
{
    if(i == 0) {return;}
    print(i-1, pre[i][p]);
    cout << p << " ";
}
int main()
{
    // freopen("P1854_7.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    }
    memset(f, -0x7f, sizeof f);
    for(int i = 0; i <= m; i++) f[0][i] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= m; j++)
        {
            for(int k = j-1; k >= i-1; k--)
            {
                if(f[i][j] < f[i-1][k])
                    f[i][j] = f[i-1][k], pre[i][j] = k;
            }
            f[i][j] += g[i][j];
        }
    }
    int ans = 0, p = 0;
    for(int i = 1; i <= m; i++)
    {
        if(ans < f[n][i]) {ans = f[n][i]; p = i;}
    }
    cout << ans << endl;
    print(n, p);
    return 0;
}