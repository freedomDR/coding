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
        // int n = nums.size();
        // vector<int> dp(n, 1);
        // for (int i = 1; i < n; i++) {
        //     for (int j = i-1; j >= 0; j--) {
        //         if (nums[i] >= nums[j])
        //             dp[i] = max(dp[i], dp[j]+1);
        //     }
        //     // cout << dp[i] << endl;
        // }
        // return n-*max_element(dp.begin(), dp.end());

        int n = nums.size();
        vector<int> g;
        for (int i = 0; i < nums.size(); i++) {
            auto it = upper_bound(g.begin(), g.end(), nums[i]);
            if (it == g.end()) {
                g.push_back(nums[i]);
            } else {
                *it = nums[i];
            }
        }
        return n-g.size();
        // 1 1 3 7 7 4 6 6 6 
    }
};
// @lc code=end

