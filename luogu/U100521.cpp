#include<bits/stdc++.h>

using namespace std;
const int maxv = 1e6+5;
int n, k, f[maxv];
struct Edge
{
    int nxt, to;
}e[maxv];
int cnt, head[maxv], in[maxv];
void addEdge(int u, int v)
{
    ++cnt;e[cnt].nxt = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

int findf(int fa)
{
    if(fa != f[fa])
        f[fa] = findf(f[fa]);
    return f[fa];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= k; i++) f[i] = i;
    for(int i = 1; i <= n; i++)
    {
        int u, v; cin >> v >> u;
        addEdge(u, v); in[v]++;
    }
    stack<int> s;
    for(int i = 1; i <= k; i++)
        if(in[i] == 0) s.push(i);
    while(!s.empty())
    {
        int u = s.top();s.pop();
        int x = findf(u);
        for(int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].to;
            int y = findf(v);
            if(x!=y) f[x] = y;
            in[v]--;
            if(in[v]==0)s.push(v);
        }
    }
    int m; cin >> m;
    while(m--)
    {
        int op; cin >> op;
        if(op == 0)
        {
            int x, y; cin >> x >> y;
            cout << (findf(x)==findf(y)?"Yes":"No") << endl;
        }else
        {
            int x; cin >> x;
            cout << findf(x) << endl;
        }
        
    }
    return 0;
}