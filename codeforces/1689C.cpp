#include <bits/stdc++.h>
using namespace std;

void slove() {
    int n; cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int from, to; cin >> from >> to;
        from--, to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    vector<int> subtree_nodes(n);
    auto dfs1 = [&](this auto && dfs1, int x, int fa) -> int {
        int sums = 0;
        for (int v:g[x]) {
            if (v == fa) continue;
            sums += dfs1(v, x)+1;
        }
        subtree_nodes[x] = sums;
        return sums;
    };
    dfs1(0, -1);
    // for (int i = 0; i < n; i++) cout << subtree_nodes[i] << " ";
    // cout << endl;

    auto dfs2 = [&](this auto && dfs2, int x, int fa) -> int {
        vector<int> child;
        for (int v:g[x]) {
            if (v == fa) continue;
            child.push_back(v);
        }
        if (child.size()==0) return 0;
        if (child.size()==1) return subtree_nodes[child[0]];
        return max(subtree_nodes[child[0]]+dfs2(child[1], x), subtree_nodes[child[1]]+dfs2(child[0], x));
    };
    cout << dfs2(0, -1) << endl;;
}

int main()
{
    int t; cin >> t;
    while (t--) {
        slove();
    }
    return 0;
}