#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4+5;
const int maxm = 1005;
int n, m, k, x[maxn], y[maxn], l[maxn], h[maxn], f[maxn][maxm], has[maxn];
int main()
{
    // freopen("P1941_5.in", "r", stdin);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        l[i+1] = 0; h[i+1] = m+1;
    }
    for(int i = 0; i < k; i++)
    {
        int v1, v2, v3;
        cin >> v1 >> v2 >> v3;
        l[v1] = v2;
        h[v1] = v3;
        has[v1] = 1;
    }
    memset(f, 0x3f, sizeof f);
    for(int i = 1; i <= m; i++) f[0][i] = 0;
    for(int i = 1; i <= n; i++)
    {
        //上升 完全背包
        for(int j = x[i-1]+1; j <= m; j++)
        {
            f[i][j] = min(f[i-1][j-x[i-1]], f[i][j-x[i-1]])+1;
        }
        for(int j = 0; j <= x[i-1]; j++)
        {
            f[i][m] = min(f[i][m], min(f[i-1][m-j], f[i][m-j])+1);
        }
        //下降 0 1
        for(int j = 1; j <= m-y[i-1]; j++)
        {
            f[i][j] = min(f[i][j], f[i-1][j+y[i-1]]);
        }
        // for(int j = 1; j <= m; j++) cout << f[i][j] << " ";
        // cout << endl;
        for(int j = 1; j <= l[i]; j++) f[i][j] = f[0][0];
        for(int j = h[i]; j <= m; j++) f[i][j] = f[0][0];
        // for(int j = 1; j <= m; j++) cout << f[i][j] << " ";
        // cout << endl;
        // int test; cin >> test;
    }
    int ans = f[0][0];
    for(int j = 1; j <= m; j++)
    {
        ans = min(ans, f[n][j]);
    }
    if(ans < f[0][0]) {cout << "1" << endl << ans << endl;}
    else
    {
        int r = n;
        for(;r>=1; r--)
        {
            int j = 1;
            for(; j <= m; j++)
                if(f[r][j] < f[0][0]) break;
            if(j <= m) break;
        }
        ans = 0;
        for(int j = 1; j <= r; j++)
            if(has[j]) ans++;
        cout << "0" << endl << ans << endl;
    }
    return 0;
}