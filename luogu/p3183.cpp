#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;
int head[maxn], nxt[maxn*2], to[maxn*2], cnt, in[maxn], n, m, f[maxn], out[maxn];
inline void addEdge(int u, int v) {++cnt;nxt[cnt] = head[u];to[cnt] = v; head[u] = cnt;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        addEdge(u, v);
        in[v]++;
        out[u]++;
    }
    stack<int> s;
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0&&out[i]!=0) {s.push(i);f[i] = 1;}
    }
    int ans = 0;
    while(!s.empty())
    {
        int u = s.top();s.pop();
        bool add = true;
        for(int i = head[u]; i; i = nxt[i])
        {
            int v = to[i];
            in[v]--;
            f[v] += f[u];
            if(in[v] == 0) s.push(v);
            add = false;
        }
        if(add) ans += f[u];
        // cout << u << " " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}