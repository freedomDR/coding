#include<bits/stdc++.h>

using namespace std;

int n, head[105], sz[105], cnt, val[105];
long long ans, f[105];

struct Edge
{
    int next;
    int to;
}e[210];

void addEdge(int u, int v)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

void dfs(int u, int fa, int dep)
{
    sz[u] = val[u];
    for(int i = head[u];i;i=e[i].next)
    {
        if(e[i].to==fa) continue;
        dfs(e[i].to, u, dep+1);
        sz[u] += sz[e[i].to];
    }
    f[1] += val[u]*dep;
}

void dp(int u, int fa)
{
    for(int i = head[u]; i; i=e[i].next)
    {
        int v = e[i].to;
        if(v==fa) continue;
        f[v] = f[u]+sz[1]-sz[v]*2;
        dp(v, u);
    }
    ans = min(ans, f[u]);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int v1, v2;
        cin >> val[i] >> v1 >> v2;
        if(v1) {addEdge(i, v1); addEdge(v1, i);}
        if(v2) {addEdge(i, v2); addEdge(v2, i);}
    }
    dfs(1, 0, 0);
    memset(&ans, 0x7f, sizeof ans);
    dp(1, 0);
    cout << ans << endl;
    return 0; 
}