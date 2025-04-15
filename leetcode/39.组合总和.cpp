/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        ranges::sort(candidates);
        vector<int> p;
        auto dfs1 = [&](this auto && self, int pos, int remain) {
            if (remain < 0) return;
            if (remain == 0) {
                res.push_back(p);
                return;
            }
            if (pos == candidates.size()) return;
            self(pos+1, remain);
            p.push_back(candidates[pos]);
            self(pos, remain-candidates[pos]);
            p.pop_back();
        };
        // dfs1(0, target);
        auto dfs2 = [&](this auto && self, int pos, int remain) {
            if (remain < 0) return;
            if (remain == 0) {
                res.push_back(p);
                return;
            }
            if (pos == candidates.size()) return;
            for (int i = pos; i < candidates.size(); i++) {
                p.push_back(candidates[i]);
                self(i, remain-candidates[i]);
                p.pop_back();
            }
        };
        dfs2(0, target);
        return res;
    }
};
// @lc code=end

