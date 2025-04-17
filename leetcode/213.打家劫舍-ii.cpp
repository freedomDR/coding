/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int robb(vector<int> & nums, int start, int end) {
        int prev = 0, curr = 0;
        for (int i = start; i < end; ++i) {
            int temp = curr;
            curr = max(curr, prev + nums[i]);
            prev = temp;
        }
        return curr;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(nums[0]+robb(nums, 2, n-1), robb(nums, 1, n));
    }
};
// @lc code=end

