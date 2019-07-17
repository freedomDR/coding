#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n, m;
    cin>>n>>m;
    vector<int> pos(n+1);
    for(int i = 0; i < n; i++)
    {
        int t = 0;
        cin>>t;
        pos[t] = i;
    }
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        if(pos[u] < pos[v])
            adj[pos[u]].push_back(pos[v]);
    }
    unordered_set<int> fail;
    fail.insert(n-1);
    int ans = 0;
    for(int i = n-2; i >= 0; i--)
    {
        int flag = fail.size();
        for(auto j:adj[i])
        {
            if(fail.count(j)) flag--;
        }
        if(flag) fail.insert(i);
        else ans++;
    }
    cout<<ans<<endl;
    return 0;
}
