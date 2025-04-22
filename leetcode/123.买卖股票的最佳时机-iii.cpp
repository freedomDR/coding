/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>> cache(n, vector<vector<int>>(3, vector<int>(2, -1)));
        // auto dfs = [&](this auto && self, int pos, int k, int hold) -> int {
        //     if (k < 0) 
        //         return INT_MIN/2;
        //     if (pos < 0)
        //         return hold?INT_MIN/2:0;
        //     auto & res = cache[pos][k][hold];
        //     if (res != -1)
        //         return res;
        //     if (hold)
        //         return res = max(self(pos-1, k, true), self(pos-1, k-1, false)-prices[pos]);
        //     return res = max(self(pos-1, k, false), self(pos-1, k, true)+prices[pos]);
        // };
        // return dfs(n-1, 2, false);

        int n = prices.size();
        vector<vector<int>> dp(4, vector<int>(2, INT_MIN/2));
        for (int i = 1; i < 4; i++)
            dp[i][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 3; j >= 1; j--) {
                dp[j][0] = max(dp[j][0], dp[j][1]+prices[i]);
                dp[j][1] = max(dp[j][1], dp[j-1][0]-prices[i]);
            }
        }
        return dp[3][0];
    }
};
// @lc code=end

