/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 1);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[i] > nums[j]) {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(), dp.end());
        vector<int> f;
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(f.begin(), f.end(), nums[i]);
            if (it == f.end()) {
                f.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return f.size();
    }
};
// @lc code=end

