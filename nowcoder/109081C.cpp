#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    unordered_map<int, vector<int>> g;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int max_len = 0;
    function<void(int, int, int)> dfs = [&](int i, int fa, int len) {
        // cout << "pos: " << i << " fa: " << fa << " len: " << len << endl;
        if (g[i].size()==1 && fa==g[i][0]) {
            max_len = max(max_len, len);
            return;
        }
        for (int to:g[i]) {
            if (to==fa) continue;
            dfs(to, i, len+1);
        }
    };
    dfs(k, -1, 0);
    cout << max_len+1 << endl;
    return 0;
}