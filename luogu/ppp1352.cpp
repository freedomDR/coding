#include<bits/stdc++.h>

using namespace std;
const int maxn = 6666;
struct Edge
{
    int next;
    int to;
}e[maxn];

int n, head[maxn], val[maxn], cnt, parent[maxn];
int out[maxn], dp[maxn][2];

void addEdge(int u, int v)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> v >> u;
        addEdge(u, v);
        parent[v] = u;
        out[u]++;
    }
    stack<int> s;
    for(int i = 1; i <= n; i++)
    {
        if(out[i] == 0) s.push(i);
    }
    int last = -1;
    while(!s.empty())
    {
        int x = s.top();
        s.pop();
        last = x;
        for(int i=head[x]; i; i=e[i].next)
        {
            int v = e[i].to;
            dp[x][0] += max(dp[v][0], dp[v][1]);
            dp[x][1] += dp[v][0];
        }
        dp[x][1] += val[x];
        if(--out[parent[x]] == 0)
        {
            s.push(parent[x]);
        }
    }
    cout << max(dp[last][0], dp[last][1]) << endl;
    return 0;
}