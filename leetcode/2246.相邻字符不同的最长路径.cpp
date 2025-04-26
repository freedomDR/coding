/*
 * @lc app=leetcode.cn id=2246 lang=cpp
 *
 * [2246] 相邻字符不同的最长路径
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                g[parent[i]].push_back(i);
            }
        }
        int ans = 0;
        auto dfs = [&](this auto && self, int node, int fa) -> int {
            int max_len = 0;
            for (int child : g[node]) {
                if (child == fa) continue;
                int len = self(child, node)+1;
                if (s[child] != s[node]) {
                    ans = max(ans, max_len + len);
                    max_len = max(max_len, len);
                }
            }
            return max_len;
        };
        dfs(0, -1);
        return ans + 1;
    }
};
// @lc code=end

