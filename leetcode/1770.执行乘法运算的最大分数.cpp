/*
 * @lc app=leetcode.cn id=1770 lang=cpp
 *
 * [1770] 执行乘法运算的最大分数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // int n = nums.size();
        // int m = multipliers.size();
        // unordered_map<int, int> cache;
        // auto dfs = [&](this auto && dfs, int i, int j, int k) -> int {
        //     if (k == m) return 0;
        //     int key = i * 1000 + k; // Unique key for cache
        //     auto it = cache.find(key);
        //     if (it != cache.end()) return it->second;
        //     int left = nums[i] * multipliers[k] + dfs(i + 1, j, k + 1);
        //     int right = nums[j] * multipliers[k] + dfs(i, j - 1, k + 1);
        //     return cache[key] = max(left, right);
        // };
        // return dfs(0, n-1, 0);
        // dp[i][j] = max(dp[i + 1][j] + nums[i] * multipliers[k], dp[i][j - 1] + nums[j] * multipliers[k]);
        // dp[i][j] = max(dp[i-1][j]+nums[i]*multipliers[k], dp[i][j-1]+nums[j]*multipliers[k]);
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));
        dp[0][0] = 0;
        for (int k = 0; k < m; k++) {
            for (int i = 0; i <= k; i++) {
                int j = k-i;
                if (i < n) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + nums[i] * multipliers[k]);
                }
                if (j < n) {
                    dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + nums[n - j - 1] * multipliers[k]);
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i <= m; i++) {
            ans = max(ans, dp[i][m - i]);
        }
        return ans;
    }
};
// @lc code=end

