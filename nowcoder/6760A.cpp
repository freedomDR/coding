#include<iostream>
#include<vector>
#define pii pair<int, int>
#define pb push_back
using namespace std;
int x, y;
void dfs(int u, int p, int dep, vector<vector<pii>> &e)
{
    if(dep%2) y++;
    else x++;
    for(auto &it:e[u])
    {
        if(it.first != p)
            dfs(it.first, u, dep+it.second, e);
    }
}
int main()
{
    int n; cin >> n;
    vector<vector<pii>> e(n+1, vector<pii>());
    for(int i = 1; i < n; i++)
    {
        int u, v, d; cin >> u >> v >> d;
        e[u].pb(pii(v, d)); 
        e[v].pb(pii(u, d)); 
    }   
    dfs(1, 1, 0, e);
    cout << 1ll*x*x*x+1ll*y*y*y << endl;
    return 0;
}