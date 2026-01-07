/*
 * @lc app=leetcode.cn id=3372 lang=cpp
 *
 * [3372] 连接两棵树后最大目标节点数目 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> generateG(vector<vector<int>> & e) {
        int n = e.size();
        vector<vector<int>> g(n+1);
        for (auto & arr:e) {
            int u = arr[0], v = arr[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return g;
    }

    int compute(vector<vector<int>> & g, int node, int k) {
        auto dfs = [&](this auto && self, int i, int parent, int level) -> int{
            if (level > k) return 0;
            int res = 1;
            for (int to:g[i]) {
                if (to==parent) continue;
                res += self(to, i, level+1);
            }
            return res;
        };
        return dfs(node, -1, 0);
    }
    
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        vector<int> ans(n+1);
        vector<vector<int>> g1 = generateG(edges1);
        vector<vector<int>> g2 = generateG(edges2);
        int max_2 = 0;
        for (int i = 0; i <= m; i++) {
            max_2 = max(max_2, compute(g2, i, k-1));
        }
        for (int i = 0; i <= n; i++) {
            ans[i] = compute(g1, i, k)+max_2;
        }
        return ans;
    }
};
// @lc code=end

