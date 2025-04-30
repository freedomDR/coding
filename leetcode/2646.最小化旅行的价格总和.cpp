/*
 * @lc app=leetcode.cn id=2646 lang=cpp
 *
 * [2646] 最小化旅行的价格总和
 */

// @lc code=start
#include <bits/stdc++.h>
#include <numbers>
using namespace std;

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0], y = edges[i][1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> used(n);
        auto dfs1 = [&](this auto && dfs1, int x, int fa, int p) -> bool{
            if (x == n) return false;
            if (x == p) return true;
            auto final_res = false;
            for (int v:g[x]) {
                if (v == fa) continue;
                auto res = dfs1(v, x, p);
                if (res) used[v]++;
                final_res |= res;
            }
            return final_res;
        };
        for (int i = 0; i < trips.size(); i++) {
            int x = trips[i][0], y = trips[i][1];
            dfs1(x, -1, y);
            used[x]++;
        }
        // for (int i = 0; i < n; i++) 
        //     cout << used[i] << " ";
        // cout << endl;


        auto dfs2 = [&](this auto && dfs2, int x, int fa) -> pair<int, int> {
            if (x == n) return {0, 0};
            int c = price[x]/2*used[x], not_c = price[x]*used[x];
            for (int v:g[x]) {
                if (v == fa) continue;
                auto [cc, not_cc] = dfs2(v, x);
                c += not_cc;
                not_c += min(cc, not_cc);
            }
            // cout << x << " " << c << " " << not_c << endl;
            return {c, not_c};
        };
        auto [v1, v2] = dfs2(0, -1);
        return min(v1, v2);
    }
};
// @lc code=end

