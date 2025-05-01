#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<vector<int>> g(n+1);
    vector<int> cost(n+1), in(n+1);
    for (int i = 1; i <= n; i++) {
        int pos; cin >> pos;
        cin >> cost[pos];
        int m; cin >> m;
        g[pos].resize(m);
        for (int i = 0; i < m; i++) {
            cin >> g[pos][i];
            in[g[pos][i]]++;
        }
    }

    int root = -1;
    for (int i = 1; i <= n; i++) 
        if (in[i]==0) root = i;
    //cout << root << endl;

    function<tuple<int, int, int>(int, int)> dfs = [&](int x, int from) -> tuple<int, int, int> {
        if (g[x].size()==0)
            return {cost[x], 0, INT_MAX/2};
        int me = cost[x], fa = 0, son = 0;
        int minv = INT_MAX;
        for (int to:g[x]) {
            auto [c_me, c_fa, c_son] = dfs(to, x);
            me += min({c_me, c_fa, c_son});
            fa += min(c_me, c_son);
            minv = min(minv, c_me-c_son);
        }
        son = fa + max(0, minv);
        return {me, fa, son};
    };
    auto [me, fa, son] = dfs(root, 0);
    cout << min(me, son) << endl;
    return 0;
}