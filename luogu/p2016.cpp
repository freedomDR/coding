#include<bits/stdc++.h>

using namespace std;

const int maxn = 1555;
struct Edge
{
    int next;
    int to;
}e[maxn];

int head[maxn], cnt, n, dp[maxn][2], out[maxn],fa[maxn];

void addEdge(int u, int v)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> i >> k;
        for(int j = 0; j < k; j++)
        {
            int v; cin >> v;
            int u = i;
            addEdge(u, v);
            out[u]++;
            fa[v] = u;
        }
    }
    queue<int> q;
    for(int i = 0; i < n; i++)
    {
        if(out[i]==0) q.push(i);
    }
    int last = -1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        last = u;
        for(int i = head[u]; i; i=e[i].next)
        {
            int v = e[i].to;
            dp[u][0] += dp[v][1];
            dp[u][1] += min(dp[v][0], dp[v][1]);
        }
        dp[u][1]++;
        out[fa[u]]--;
        if(out[fa[u]]==0) q.push(fa[u]);
    }
    cout << min(dp[last][0], dp[last][1]) << endl;
    return 0;
}