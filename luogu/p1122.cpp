#include<bits/stdc++.h>

using namespace std;

int n, ans = INT_MIN;
vector<int> v, dp;
vector<vector<int>> e;

void dfs(int p, int fa)
{
    dp[p] = v[p];
    for(auto it:e[p])
    {
        if(it == fa) continue;
        dfs(it, p);
        dp[p] += max(dp[it], 0);
    }
    ans = max(ans, dp[p]);
}
int main()
{
    cin >> n;
    e.resize(n+1);
    v.resize(n+1);
    dp.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    for(int i = 1; i < n; i++)
    {
        int uu, vv; cin >> uu >> vv;
        e[uu].push_back(vv);
        e[vv].push_back(uu);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}