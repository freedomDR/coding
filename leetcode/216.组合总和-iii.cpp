/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> p;
        auto dfs1 = [&](this auto && self, int pos, int sums) {
            if (p.size() == k) {
                if (sums == n) ans.push_back(p);
                return;
            }
            for (int i = pos; i <= 9; i++) {
                p.push_back(i);
                self(i + 1, sums + i);
                p.pop_back();
            }
        };
        // dfs1(1, 0);
        auto dfs2 = [&](this auto && self, int pos, int sums) {
            if (p.size() == k) {
                if (sums == n) ans.push_back(p);
                return;
            }
            if (pos > 9) return;
            self(pos+1, sums);
            p.push_back(pos);
            self(pos + 1, sums + pos);
            p.pop_back();
        };
        dfs2(1, 0);
        return ans;
    }
};
// @lc code=end

