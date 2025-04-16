/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> p;
        auto dfs = [&](this auto && self, int pos) {
            if (pos == nums.size()) {
                ans.push_back(p);
                return;
            }
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                used[i] = true;
                p.push_back(nums[i]);
                self(pos + 1);
                p.pop_back();
                used[i] = false;
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

