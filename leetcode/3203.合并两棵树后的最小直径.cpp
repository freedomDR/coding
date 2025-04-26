/*
 * @lc app=leetcode.cn id=3203 lang=cpp
 *
 * [3203] 合并两棵树后的最小直径
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {

    int maxDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> g(n+1);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int ans = 0;
        auto dfs = [&](this auto && self, int u, int fa) -> int {
            int max_len = 0;
            for (int v:g[u] ) {
                if (v == fa) continue;
                auto len = self(v, u)+1;
                ans = max(ans, max_len + len);
                max_len = max(max_len, len);
            }
            return max_len;
        };
        dfs(0, -1);
        return ans;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto d1 = maxDiameter(edges1);
        auto d2 = maxDiameter(edges2);
        return max({
            d1, 
            d2,
            (d1 + 1) / 2 + (d2 + 1) / 2 + 1,
        });
    }
};
// @lc code=end

