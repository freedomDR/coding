#include<bits/stdc++.h>

using namespace std;
const int maxn = 1e5+5;
const int maxm = 2e5+5;
int n, m, head[maxn], nxt[maxm], to[maxm], cnt, in[maxn], out[maxn], ans[maxn];
void addEdge(int u, int v)
{
    ++cnt;
    nxt[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        out[u]++;
        in[v]++;
    }
    stack<int> s;
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0) {s.push(i);ans[i] = 1;}
    }
    while(!s.empty())
    {
        int u = s.top(); s.pop();
        for(int i = head[u]; i; i = nxt[i])
        {
            int v = to[i];
            ans[v] = max(ans[v], ans[u]+1);
            in[v]--;
            if(in[v] == 0) s.push(v);
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}