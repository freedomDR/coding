#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int f[400001], used[400001], broken[400001];
vector<vector<int>> edge(400001, vector<int>());

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y)
{
    int xf = find(x), yf = find(y);
    if(xf != yf) f[xf] = yf;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) f[i] = i;
    for(int i = 0; i < m; i++) {int u, v; cin >> u >> v;edge[u].push_back(v);edge[v].push_back(u);}
    cin >> k;
    for(int i = 0; i < k; i++) {cin >> broken[i]; used[broken[i]] = 1;}
    int total = n-k;
    for(int i = 0; i < n; i++) 
    {
        if(used[i] == 1) continue;
        for(auto v:edge[i])
        {
            if(used[v] == 1) continue;
            if(find(i) != find(v)) total--, f[find(i)] = find(v);
        }
    }
    vector<int> ans;
    ans.push_back(total);
    for(int i = k-1; i >= 0; i--)
    {
        int u = broken[i];
        total++;
        for(auto v:edge[u])
        {
            if(used[v] == 1) continue;
            if(find(v) != find(u)) total--, f[find(v)] = find(u);
        }
        used[u] = 0;
        ans.push_back(total);
    }
    for(auto i = ans.rbegin(); i < ans.rend(); i++)
    {
        cout << *i << endl;
    }
    return 0;
}
