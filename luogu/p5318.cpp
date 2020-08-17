#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int p, vector<bool> &vis, vector<vector<int>> &e)
{
    vis[p] = true;
    cout << p << " ";
    for(auto &v:e[p])
    {
        if(!vis[v])
            dfs(v, vis, e);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n, m; cin >> n >> m;
    vector<vector<int>> e(n+1, vector<int>());
    vector<pair<int, int>> a;
    for(int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        a.push_back(make_pair(u, v));
    }
    sort(a.begin(), a.end());
    for(auto &it:a)
    {
        e[it.first].push_back(it.second);
    }
    vector<bool> vis(n+1, false);
    dfs(1, vis, e);
    cout << endl;
    fill(vis.begin(), vis.end(), false);
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for(auto v:e[u])
        {
            if(!vis[v])
                q.push(v);
            vis[v] = true;
        }
    }
    return 0;
}