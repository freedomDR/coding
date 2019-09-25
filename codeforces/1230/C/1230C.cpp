#include<bits/stdc++.h>
using namespace std;
bool vis_v[7];
int val_v[8];
int ans, n, m, dom[7][7], a[22], b[22];

void dfs(int pos)
{
    if(pos == n+1)
    {
        int sums = 0;
        memset(dom, 0, sizeof(dom));
        for(int i = 1; i <= m; i++)
        {
            int u = val_v[a[i]];
            int v = val_v[b[i]];
            if(u > v) swap(u, v);
            if(dom[u][v] == 0) 
            {
                sums++;
                dom[u][v] = 1;
            }
        }
        ans = max(ans, sums);
        return;
    }
    for(int i = 1; i <= 6; i++)
    {
        val_v[pos] = i;
        dfs(pos+1);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++) 
    {
        int u, v; cin >> u >> v;
        a[i] = u; b[i] = v;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
