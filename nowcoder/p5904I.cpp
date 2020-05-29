#include<bits/stdc++.h>

using namespace std;
int g[11][11], n, m;
int main()
{
    cin >> n >> m;
    bool ok = true;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> g[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            int v; cin >> v;
            if(v != g[i][j]) ok = false;
        }
    cout << (ok?"Yes":"No") << endl;
    return 0;
}