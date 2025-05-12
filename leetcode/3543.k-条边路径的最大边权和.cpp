/*
 * @lc app=leetcode.cn id=3543 lang=cpp
 *
 * [3543] K 条边路径的最大边权和
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        // solution 1
        int ans = -1;
        vector<vector<pii>> g(n);
        for (auto & arr:edges) {
            int x = arr[0], y = arr[1], cost = arr[2];
            g[x].emplace_back(y, cost);
        }
        unordered_set<int> vis;
        auto dfs = [&](this auto && self, int i, int kk, int s) {
            if (kk==k) {
                ans = max(ans, s);
                return;
            }
            int v = i<<20|kk<<10|s;
            if (vis.contains(v)) return;
            vis.insert(v);
            for (auto [to, cost]:g[i]) {
                if (s+cost<t) {
                    self(to, kk+1, s+cost);
                }
            }
        };
        for (int i = 0; i < n; i++)
            dfs(i, 0, 0);
        return ans;
    }
};
// @lc code=end

