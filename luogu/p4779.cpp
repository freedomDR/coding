#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5+5;
int n, m, s, u, v, w;
long long dis[maxn];
bool vis[maxn];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

struct Edge{
    int next;
    int to;
    int w;
}e[maxn*2];
int head[maxn], cnt;

void addEdge(int u, int v, int w)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    e[cnt].w = w;
    head[u] = cnt;
}

int main()
{
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    fill(dis, dis+n+1, LLONG_MAX);
    dis[s] = 0;
    q.push(make_pair(0, s));
    while(!q.empty())
    {
        auto t = q.top(); q.pop();
        u = t.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = head[u]; i; i = e[i].next)
        {
            v = e[i].to;
            w = e[i].w;
            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u]+w;
                if(!vis[v])
                q.push(make_pair(dis[v], v));
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;
    return 0;
}