#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, bool> visit;
vector<vector<int>> g;
vector<int> height;
int m, n, ans;

void dfs(int s, int v)
{
    bool have_choice = false;
    for(int i = 0; i < g[s].size(); i++)
    {
        int u = max(s, g[s][i]);
        int v = min(s, g[s][i]);
        auto edge = make_pair(u, v);
        if(visit[edge] == false) 
        {
            have_choice = true;
            visit[edge] = true;
            dfs(g[s][i], v+height[g[s][i]]);
            visit[edge] = false;
        }
    }
    if(have_choice == false) ans = max(ans, v);
}

int main()
{
    cin >> n >> m;
    height.resize(n+1);
    g.resize(n+1);
    for(int i = 1; i <= n; i++) cin >> height[i];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int s;
    cin >> s;
    dfs(s, height[s]);
    cout << ans << endl;
    return 0;
}
