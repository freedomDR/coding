/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> p;
        auto dfs = [&](this auto && self, int pos) {
            if (p.size() == k) {
                ans.push_back(p);
                return;
            }
            for (int i = pos; i <= n; i++) {
                p.push_back(i);
                self(i+1);
                p.pop_back();
            }
        };
        // dfs(1);
        auto dfs2 = [&](this auto && self, int pos) {
            if (p.size() == k) {
                ans.push_back(p);
                return;
            }
            if (pos > n) return;
            self(pos+1);
            p.push_back(pos);
            self(pos+1);
            p.pop_back();

        };
        dfs2(1);
        return ans;
    }
};
// @lc code=end

