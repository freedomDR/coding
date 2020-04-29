#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5+5;
int n, p1, p2;
struct Edge
{
    int nxt, from, to, f, offset;
}e[maxn*3];
int cnt, head[maxn], in[maxn];
void addEdge(int u, int v, int f)
{
    ++cnt;
    e[cnt].nxt = head[u];
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].f = f;
    head[u] = cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("P2017_3.in", "r", stdin);
    cin >> n >> p1 >> p2;
    for(int i = 1; i <= p1; i++)
    {
        int u, v; cin >> u >> v;
        addEdge(u, v, 1);
        in[v]++;
    }
    if(cnt%2 == 0) cnt++;
    for(int i = 1; i <= p2; i++)
    {
        int u, v; cin >> u >> v;
        addEdge(u, v, 2);
        addEdge(v, u, 2);
    }
    stack<int> q;
    for(int i = 1; i <= n; i++) if(in[i]==0) q.push(i);
    while(!q.empty())
    {
        int u = q.top(); q.pop();
        for(int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to, f = e[i].f;
            if(f == 1)
            {
                in[v]--;
                if(in[v]==0)q.push(v);
            }else if(f==2)
            {
                e[i^1].f = 0;
            }
        }
    }
    for(int i = 1; i <= cnt; i++)
    {
        if(e[i].f == 2) cout << e[i].from << " " << e[i].to << endl;
    }
    return 0;
}