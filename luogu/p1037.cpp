#include<bits/stdc++.h>

using namespace std;
string s;
int k, e[10][10], cnt[10], vis[10], ans[35], len;

void cal(int b)
{
    for(int i = 1; i <= len; i++)
    {
        ans[i] *= b;
    }
    for(int i = 1; i <= len; i++)
    {
        ans[i+1] += ans[i]/10;
        ans[i] %= 10;
    }
    while(ans[len+1] != 0) 
    {
        len++;
        ans[len+1] = ans[len]/10;
        ans[len] %= 10;
    }
}

void dfs(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    for(int i = 1; i <= e[u][0]; i++)
    {
        dfs(e[u][i]);
    }
}

int main()
{
    /* freopen("./test.in", "r", stdin); */
    cin >> s >> k;
    for(int i = 0; i < k; i++)
    {
        int u, v; cin >> u >> v;
        int len = e[u][0];
        e[u][len+1] = v;
        e[u][0]++;
    }
    for(int i = 0; i < 10; i++)
    {
        memset(vis, 0, sizeof vis);
        dfs(i);
        for(int j = 0; j < 10; j++) cnt[i] += vis[j];
    }
    ans[1] = 1;
    len = 1;
    for(auto &c:s)
    {
        cal(cnt[c-'0']); 
    }
    for(int i = len; i >= 1; i--)
        cout << ans[i];
    return 0;
}
