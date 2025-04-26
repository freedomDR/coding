/*
 * @lc app=leetcode.cn id=1617 lang=cpp
 *
 * [1617] 统计子树中城市之间最大距离
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // solution 1
        // vector<int> ans(n-1);
        // vector<vector<int>> g(n+1);
        // for (auto& e : edges) {
        //     g[e[0]].push_back(e[1]);
        //     g[e[1]].push_back(e[0]);
        // }   
        // int diameter = 0;
        // vector<int> vis(n+1, 0), st(n+1, 0);
        // auto dfs = [&](this auto && self, int u) -> int {
        //     vis[u] = 1;
        //     int max_len = 0;
        //     for (int v:g[u]) {
        //         if (!vis[v] && st[v]) {
        //             int len = self(v)+1;
        //             diameter = max(diameter, max_len+len);
        //             max_len = max(max_len, len);
        //         }
        //     }
        //     return max_len;
        // };
        // auto dfs2 = [&](this auto && self, int pos) -> void {
        //     if (pos == n+1) {
        //         for (int p = 1; p <= n; p++) {
        //             if (st[p]) {
        //                 diameter = 0;
        //                 fill(vis.begin(), vis.end(), 0);
        //                 dfs(p);
        //                 break;
        //             }
        //         }
        //         if (diameter > 0 && vis == st) {
        //             ans[diameter-1]++;
        //         }
        //         return;
        //     }
        //     self(pos+1);
        //     st[pos] = 1;
        //     self(pos+1);
        //     st[pos] = 0;
        // };
        // dfs2(1);
        // return ans;

        // solution 2
        vector<int> ans(n-1);
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }
        for (int i = 3; i < (1<<15); i++) {
            if ((i & (i - 1)) == 0) continue; // skip only one bit 
            int vis = 0;
            int diameter = 0;
            auto dfs = [&](this auto && self, int u) -> int {
                vis |= (1<<u);
                int max_len = 0;
                for (int v:g[u]) {
                    if ((vis&(1<<v))==0 && (i&(1<<v))) {
                        int len = self(v)+1;
                        diameter = max(diameter, max_len+len);
                        max_len = max(max_len, len);
                    }
                }
                return max_len;
            };
            for (int j = 0; j < n; j++) {
                if ((i&(1<<j))==0) continue;
                if ((vis&(1<<j))==0) {
                    diameter = 0;
                    dfs(j);
                    break;
                }
            }
            if (diameter > 0 && vis == i) {
                ans[diameter-1]++;
            }
        }
        return ans;
    }
};
// @lc code=end

