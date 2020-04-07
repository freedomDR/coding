#include<bits/stdc++.h>

using namespace std;

int n, q, cnt, head[105];

struct Edge
{
    int next;
    int to;
    int val;
}e[210];

void addEdge(int u, int v, int val)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].val = val;
    head[u] = cnt;
}

int dp[110][110], sz[105];

void dfs(int u, int fa)
{
    for(int i = head[u];i; i=e[i].next)
    {
        int v = e[i].to;
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v]+1;
        //dp[i][j] = max(dp[i][j], dp[u])
        for(int j=min(q, sz[u]);j; j--)
        {
            for(int k = min(sz[v], j-1); k>=0;k--)
            {
                dp[u][j] = max(dp[u][j], dp[u][j-k-1]+dp[v][k]+e[i].val);
            }
        }
    }
}

int main()
{
    cin >> n >> q;
    for(int i = 1; i < n; i++)
    {
        int u, v, val;
        cin >> u >> v >> val;
        addEdge(u, v, val);
        addEdge(v, u, val);
    }
    dfs(1, 0);
    cout << dp[1][q] << endl;
    return 0; 
}