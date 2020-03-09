#include<bits/stdc++.h>

using namespace std;

int dp[5050], n, m, in[5050], out[5050];
const int mod = 80112002;
unordered_map<int, vector<int>> mp;

int dfs(int i)
{
    if(dp[i]) return dp[i];
    for(auto ii:mp[i])
    {
        dp[i] += dfs(ii);
        dp[i] %= mod;
    }
    if(dp[i] == 0) dp[i] = 1;
    return dp[i];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.in", "r", stdin);
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        mp[v].push_back(u);
        in[u]++;
        out[v]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(in[i] == 0 && out[i] > 0)
        {
            ans += dfs(i);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}