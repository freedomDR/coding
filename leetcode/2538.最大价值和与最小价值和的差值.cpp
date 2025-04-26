/*
 * @lc app=leetcode.cn id=2538 lang=cpp
 *
 * [2538] 最大价值和与最小价值和的差值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        auto dfs = [&](this auto && self, int u, int fa) -> pair<long long, long long> {
            long long max_s1 = price[u], max_s2 = 0;
            for (int v:g[u]) {
                if (v == fa) continue;
                auto [s1, s2] = self(v, u);
                ans = max(ans, max(max_s1 + s2, max_s2 + s1));
                max_s1 = max(max_s1, s1+price[u]);
                max_s2 = max(max_s2, s2+price[u]);
            }
            return {max_s1, max_s2};
        };
        dfs(0, -1);
        return ans;
    }
};
// @lc code=end

