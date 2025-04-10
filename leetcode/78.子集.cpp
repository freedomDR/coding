/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> p;
        auto dfs = [&](this auto && self, int pos) {
            if (pos == nums.size()) {
                ans.push_back(p);
                return;
            }
            self(pos+1);
            p.push_back(nums[pos]);
            self(pos+1);
            p.pop_back();
        };
        // dfs(0);
        auto dfs2 = [&](this auto && self, int pos) {
            ans.push_back(p);
            if (pos == nums.size()) return;
            for (int i = pos; i < nums.size(); i++) {
                p.push_back(nums[i]);
                self(i+1);
                p.pop_back();
            }
        };
        dfs2(0);
        return ans;
    }
};
// @lc code=end

