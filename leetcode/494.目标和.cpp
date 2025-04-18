/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        int v = (s+target);
        if (v<0 || v%2==1)
            return 0;
        v = v/2;
        vector<int> f(v+1, 0);
        f[0] = 1;
        // dp[i][c] = dp[i-1][c] + (dp[i-1][c-v])
        for (int i = 0; i < nums.size(); i++) {
            auto c = nums[i];
            for (int j = v; j >= c; j--) {
                f[j] = f[j] + f[j-c];
            }
        }
        return f[v];
    }
};
// @lc code=end

