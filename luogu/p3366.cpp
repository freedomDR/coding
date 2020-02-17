#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 5050, M = 2*1e5+10;

int head[N], dis[N], vis[N], tot;

typedef struct T
{
    int next;
    int to;
    int val;
}E;

E e[M<<1];

void addEdge(int u, int v, int val)
{
    e[++tot].next = head[u];
    head[u] = tot;
    e[tot].to = v;
    e[tot].val = val;
}

void prim()
{
    int es = 0, ans = 0;
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for(int i = head[1];i;i = e[i].next)
    {
        dis[e[i].to] = min(dis[e[i].to], e[i].val);
    }
    int now = 1;
    while(++es < n)
    {
        vis[now] = 1;
        int minn = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn = dis[i];
                now = i;
            }
        }
        //if(minn == 0x3f) {cout << "orz" << endl; return;}
        ans += minn;
        for(int i = head[now];i;i=e[i].next)
        {
            int to = e[i].to;
            if(!vis[to]&&dis[to]>e[i].val)
            {
                dis[to] = e[i].val;
            }
        }
    }
    //cout << "----" << endl;
    cout << ans << endl;
}

int main()
{
    cin >> n >> m;
    cout << n << m << endl;
    for(int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    cout << n << endl;
    prim();
    return 0;
}
