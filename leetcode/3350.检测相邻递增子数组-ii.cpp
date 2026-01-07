/*
 * @lc app=leetcode.cn id=3350 lang=cpp
 *
 * [3350] 检测相邻递增子数组 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, pre_len = 0, cur_len = 0;
        for (int i = 0; i < n; i++) {
            cur_len++;
            if (i == n-1 || nums[i] >= nums[i+1]) {
                ans = max({ans, cur_len/2, min(pre_len, cur_len)});
                pre_len = cur_len;
                cur_len = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

