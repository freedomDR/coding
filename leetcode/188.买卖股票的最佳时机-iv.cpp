/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<unordered_map<bool, int>>> cache(n, vector<unordered_map<bool, int>>(k+1));
        // auto dfs = [&](this auto && self, int pos, int kk, bool flag) -> int{
        //     if (kk < 0)
        //         return INT_MIN/2;
        //     if (pos < 0)
        //         return flag ? INT_MIN/2:0;
        //     if (cache[pos][kk].contains(flag))
        //         return cache[pos][kk][flag];
        //     cache[pos][kk][flag] = -1;
        //     auto & res = cache[pos][kk][flag];
        //     if (flag)
        //         return res = max(self(pos-1, kk, true), self(pos-1, kk-1, false)-prices[pos]);
        //     return res = max(self(pos-1, kk, false), self(pos-1, kk, true)+prices[pos]);
        // };
        // return dfs(n-1, k, false);

        // dp[i+1][k][0] = max(dp[i][k][0], dp[i][k-1][1]+prices[i])
        // dp[i+1][k][1] = max(dp[i][k][1], dp[i][k][0]-prices[i])
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+2, vector<int>(2, INT_MIN/2)));
        // for (int i = 1; i <= k+1; i++) 
        //     dp[0][i][0] = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 1; j <= k+1; j++) {
        //         dp[i+1][j][1] = max(dp[i][j][1], dp[i][j][0]-prices[i]);
        //         dp[i+1][j][0] = max(dp[i][j][0], dp[i][j-1][1]+prices[i]);
        //     }
        // }
        // return dp[n][k+1][0];

        int n = prices.size();
        vector<vector<int>> dp(k+2, vector<int>(2, INT_MIN/2));
        for (int i = 1; i <= k+1; i++) 
            dp[i][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k+1; j++) {
                dp[j][1] = max(dp[j][1], dp[j][0]-prices[i]);
                dp[j][0] = max(dp[j][0], dp[j-1][1]+prices[i]);
            }
        }
        return dp[k+1][0];
    }
};
// @lc code=end

