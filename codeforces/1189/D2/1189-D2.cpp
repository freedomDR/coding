#include<bits/stdc++.h>
using namespace std;
typedef struct {
    int u, v, val;
}edge;
int u1, u2, v1, v2;
void dfs(int node, int p, int isU, vector<vector<int>>& tree) {
    if(tree[node].size() == 1) {
        if(isU == 1) {
            if(u1 == -1) u1 = node;
            u2 = node;
        } else {
            if(v1 == -1) v1 = node;
            v2 = node;
        }
    }
    for(int i = 0; i < int(tree[node].size()); i++) {
        int next =  tree[node][i];
        if(next == p) continue;
        dfs(next, node, isU, tree);
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> tree(n);
    vector<edge> e;
    for(int i = 1; i < n; i++) {
        int u, v, val; cin >> u >> v >> val;
        u--; v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
        e.push_back((edge){u, v, val});
    }
    for(int i = 0; i < n; i++) {
        if(tree[i].size() == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    vector<edge> ans;
    for(int i = 1; i < n; i++) {
        int u, v, val;
        u = e[i-1].u; v = e[i-1].v; val = e[i-1].val;
        u1 = u2 = v1 = v2 = -1;
        dfs(u, v, 1, tree); dfs(v, u, 0, tree); 
        ans.push_back((edge){u1, v1, val/2});
        ans.push_back((edge){u2, v2, val/2});
        if(u1 != u2) ans.push_back((edge){u1, u2, -val/2}); 
        if(v1 != v2) ans.push_back((edge){v1, v2, -val/2}); 
    }
    cout << ans.size() << endl;
    for(int i = 0; i < int(ans.size()); i++) {
        cout << (ans[i].u + 1) << " " << (ans[i].v + 1) << " " << ans[i].val << endl;
    }
    return 0;
}
