/*
 * @lc app=leetcode.cn id=2826 lang=cpp
 *
 * [2826] 将三个组排序
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n, 1);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         if (nums[i] >= nums[j]) {
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //     }
        // }
        // return n - *max_element(dp.begin(), dp.end());
        vector<int> f;
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(f.begin(), f.end(), nums[i]);
            if (it == f.end()) {
                f.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return n - f.size();
    }
};
// @lc code=end

