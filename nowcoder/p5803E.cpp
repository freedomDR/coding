#include<bits/stdc++.h>

using namespace std;
int g[1010][1010], n;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            if(g[i][j] == -1) g[i][j] = 20000;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int minn = 20000;
        for(int j = 1; j <= n; j++)
        {
            minn = min(minn, g[i][j]);
        }
        for(int j = 1; j <= n; j++)
        {
            g[i][j] -= minn;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int minn = 20000;
        for(int j = 1; j <= n; j++)
        {
            minn = min(minn, g[j][i]);
        }
        for(int j = 1; j <= n; j++)
        {
            g[j][i] -= minn;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(g[i][j]) ans = 20000-g[i][j];
    cout << ans << endl;
    return 0;
}