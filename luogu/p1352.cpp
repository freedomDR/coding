#include<bits/stdc++.h>

using namespace std;

const int maxn = 6666;

struct Edge
{
    int next;
    int to;
}e[maxn];

int head[maxn], n, cnt, val[maxn];

void addEdge(int u, int v)
{
    cnt++;
    e[cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}
int dp[maxn][2], in[maxn];
//dp[x][0] = sums(max(dp[y][0], dp[y][1]))
//dp[x][1] = sums(dp[y][0]) + val[x]
void dfs(int x)
{
    for(int i=head[x]; i; i=e[i].next)
    {
        int v = e[i].to;
        dfs(v);
        dp[x][0]+=max(dp[v][0], dp[v][1]);
        dp[x][1]+= dp[v][0];
    }
    dp[x][1] += val[x];
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
    for(int i = 1; i <= n; i++)
    {
        if(in[i]==0) root=i;
    }
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    return 0;
}