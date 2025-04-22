/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] 表示第i天不持有股票的最大收益
        // dp[i][1] 表示第i天持有股票的最大收益
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
        // ori_f0 = f0;
        // f0 = max(f0, f1+p[i])
        // f1 = max(f1, ori_f0-p[i])
        int n = prices.size();
        int f0 = 0, f1 = INT_MIN/2;
        for (int i = 0; i < prices.size(); i++) {
            auto ori_f0 = f0;
            f0 = max(f0, f1+prices[i]);
            f1 = max(f1, ori_f0-prices[i]);
        }
        return f0;
    }
};
// @lc code=end

