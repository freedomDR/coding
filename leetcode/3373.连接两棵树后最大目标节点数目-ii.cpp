/*
 * @lc app=leetcode.cn id=3373 lang=cpp
 *
 * [3373] 连接两棵树后最大目标节点数目 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> buildG(vector<vector<int>> & e) {
        int n = e.size()+1;
        vector<vector<int>> g(n);
        for (auto & arr:e) {
            int u = arr[0], v = arr[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        return g;
    }

    void deal(vector<bool> & f, vector<vector<int>> & g) {
        int n = f.size();
        auto dfs = [&](this auto && self, int node, int parent, bool val) -> void {
            f[node] = val;
            bool nxt_val = false;
            if (val == false) nxt_val = true;
            for (int to:g[node]) {
                if (parent == to) continue;
                self(to, node, nxt_val);
            }
        };
        dfs(0, -1, true);
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        auto g1 = buildG(edges1);
        auto g2 = buildG(edges2);
        // g2
        vector<bool> f1(n), f2(m);
        deal(f1, g1);
        deal(f2, g2);
        int max_2 = 0;
        for (int i = 0; i < m; i++) 
            if (f2[i]) max_2++;
        max_2 = max(max_2, m-max_2);
        vector<int> ans(n);
        int true_cnt = 0;
        for (int i = 0; i < n; i++)
            if (f1[i]) true_cnt++;
        for (int i = 0; i < n; i++) {
            if (f1[i]) ans[i] = true_cnt+max_2;
            else ans[i] = (n-true_cnt)+max_2;
        }
        return ans;
    }
};
// @lc code=end

