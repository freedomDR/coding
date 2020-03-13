#include<bits/stdc++.h>

using namespace std;

const int maxn = 33333, maxm = 100;

struct Edge
{
    int next;
    int to;
}e[maxm];

struct T
{
    int v, p, q;
}t[100];

int head[maxm], cnt, n, m, dp[maxn], tmp[maxn];

void addEdge(int u, int v)
{
    e[++cnt].next = head[u];
    e[cnt].to = v;
    head[u] = cnt;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        cin >> t[i].v >> t[i].p >> t[i].q;
        t[i].p *= t[i].v;
        if(t[i].q)
            addEdge(t[i].q, i);
    }
    for(int i = 1; i <= m; i++)
    {
        if(t[i].q==0)//类似于分组背包
        {
            //选择主件
            memset(tmp, 0, sizeof(tmp));
            //先计算加上主件的
            for(int j = t[i].v; j <= n; j++)
                tmp[j] = dp[j-t[i].v]+t[i].p;
            //计算附件的
            for(int j = head[i]; j; j=e[j].next)
            {
                int v = e[j].to;
                //01 背包
                for(int k = n; k >=t[i].v+t[v].v; k--)
                    tmp[k] = max(tmp[k], tmp[k-t[v].v]+t[v].p);
            }
            //和不选这组的进行比较
            for(int j = t[i].v; j <= n; j++)
                dp[j] = max(dp[j], tmp[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}