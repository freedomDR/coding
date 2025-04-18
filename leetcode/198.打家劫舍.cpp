/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int f0 = 0, f1 = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(f1, f0+nums[i]);
            f0 = f1;
            f1 = ans;
        }
        return ans;
    }
};
// @lc code=end

