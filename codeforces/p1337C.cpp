#include<bits/stdc++.h>

using namespace std;
void dfs(int fa, vector<vector<int>> &e, vector<int> &val, vector<int> &sz, int dep)
{
    sz[fa] = 1;
    for(auto son:e[fa])
    {
        if(sz[son]) continue;
        dfs(son, e, val, sz, dep+1);
        sz[fa] += sz[son]; 
    }
    val[fa] = dep-sz[fa];
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> e(n+1, vector<int>());
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    vector<int> val(n+1), sz(n+1);
    long long ans = 0;
    dfs(1, e, val, sz, 1);
    sort(val.begin()+1, val.end());
    reverse(val.begin()+1, val.end());
    for(int i = 0; i < k; i++)
    {
        ans += val[i+1];
    }
    cout << ans << endl;
    return 0;
}