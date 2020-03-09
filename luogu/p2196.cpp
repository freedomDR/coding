#include<bits/stdc++.h>

using namespace std;

int e[25][25], n, g[25], v[25], vis[25], ans[25], len;
int get(int i)
{
    if(g[i]) return g[i];
    int tmp = 0;
    for(int p = 1; p <= n; p++)
    {
        if(e[i][p] && !vis[p])
        {
            vis[p] = 1;
            tmp = max(get(p), tmp);  
            vis[p] = 0;
        }      
    }
    return g[i] = tmp+v[i];
}

void dfs(int p)
{
    int tmp = 0, pos = 0;
    for(int i = 1; i <= n; i++)
    {
        if(e[p][i]&&!vis[i])
        {
            vis[i] = 1;
            int ttmp = get(i);
            if(tmp<ttmp)
            {
                tmp = ttmp;
                pos = i;
            }
            vis[i] = 0;
        }
    }
    if(pos==0) return;
    ans[++len] = pos;    
    dfs(pos);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i < n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            cin >> e[i][j];
        }
    }
    int sums = 0, st = 0;
    for(int i = 1; i <= n; i++)
    {
        vis[i] = 1;
        int tmp = get(i);
        if(tmp > sums)
        {
            sums = tmp;
            st = i;
        }
        vis[i] = 0;
    }
    ans[++len] = st;
    dfs(st);
    for(int i = 1; i <= len; i++) cout << ans[i] << " ";
    cout << endl;
    cout << sums << endl;
    return 0;
}