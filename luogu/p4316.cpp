#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5+5;
struct Edge{
    int from, to, nxt, val;
}e[maxn*2];
int cnt, head[maxn], n, m, in[maxn], dg[maxn];
double f[maxn];
void addEdge(int u, int v, int w)
{
    ++cnt;
    e[cnt].nxt = head[u];
    e[cnt].to  = v;
    e[cnt].from = u;
    e[cnt].val = w;
    head[u] = cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        addEdge(v, u, w);
        in[u]++;
        dg[u]++;
    }
    stack<int> s;
    s.push(n);
    while(!s.empty())
    {
        int u = s.top();s.pop();
        for(int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            f[v] += (f[u]+e[i].val)/dg[v];
            in[v]--;
            if(in[v]==0) s.push(v);
        }
    }
    printf("%0.2f\n", f[1]);
    return 0;
}