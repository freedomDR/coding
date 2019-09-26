#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[100100], ans, MOD=ll(1e9+7);
vector<vector<ll>> edge(100100);
int n;

void dfs(int cur, int pre, const unordered_map<ll, int>& pre_map)
{
    unordered_map<ll, int> map;
    for(auto &it:pre_map)
        map[__gcd(it.first, x[cur])] += it.second;
    map[x[cur]]++;
    for(auto &it:map)
    {
        ans += ((it.first%MOD) * (it.second%MOD))%MOD;
        ans %= MOD;
    }
    /* cout << ans << endl; */
    for(auto &it:edge[cur])
        if(it != pre)
            dfs(it, cur, map);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 0, {});
    cout << ans << endl;
    return 0;
}
