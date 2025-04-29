#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(vector<vector<int>> & g, int node, vector<int> & cost) {
    int cur_choice = cost[node];
    int cur_not_choice = 0;
    for (int i = 0; i < g[node].size(); i++) {
        auto [choice, not_choice] = dfs(g, g[node][i], cost);
        cur_choice += not_choice;
        cur_not_choice += max(choice, not_choice);
    }
    return {cur_choice, cur_not_choice};
}

int main()
{
    int n; cin >> n;
    vector<int> in(n), cost(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for (int i = 1; i < n; i++) {
        int from, to;
        cin >> to >> from;
        from--; to--;
        g[from].push_back(to);
        in[to]++;
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (in[i]==0) {
            root = i;
            break;
        }
    }
    auto [choice, not_choice] = dfs(g, root, cost);
    cout << max(choice, not_choice) << endl;
    return 0;
}