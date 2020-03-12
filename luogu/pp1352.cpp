#include<bits/stdc++.h>

using namespace std;

const int maxn = 6666;

struct Edge
{
    int next;
    int to;
}e[maxn];
int head[maxn], n, cnt, val[maxn];
int dp[maxn][2], in[maxn], p[maxn];
void addEdge(int u, int v)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> v >> u;
        addEdge(u, v);
        in[v]++;
    }
    int root = 0;
    for(int i = 1; i <= n; i++) if(!in[i]) root = i;
    deque<int> q;
    q.push_back(root);
    int pos = 0;
    while(!q.empty())
    {
        int x = q.front();
        p[++pos] = x;
        q.pop_front();
        for(int i = head[x]; i; i=e[i].next)
        {
            int v = e[i].to;
            q.push_back(v);
        }
    }
    for(int i = pos; i >= 1; i--)
    {
        int x = p[i];
        for(int j = head[x]; j; j = e[j].next)
        {
            int v = e[j].to;
            dp[x][0] += max(dp[v][0], dp[v][1]);
            dp[x][1] += dp[v][0];
        }
        dp[x][1] += val[x];
    }
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}