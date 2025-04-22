/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // int n = prices.size();
        // vector<vector<int>> cache(n, vector<int>(2, INT_MIN));
        // auto dfs = [&](this auto && self, int pos, int hold) -> int {
        //     if (pos < 0) 
        //         return hold?INT_MIN/2:0;
        //     auto & res = cache[pos][hold];
        //     if (res != INT_MIN)
        //         return res;
        //     if (hold)
        //         return res = max(self(pos-1, 1), self(pos-1, 0)-prices[pos]);
        //     return res = max(self(pos-1, 0), self(pos-1, 1)+prices[pos]-fee);
        // };
        // return dfs(n-1, 0);

        int n = prices.size();
        // dp[i+1][1] = max(dp[i][1], dp[i][0]-p[i+1]);
        // dp[i+1][0] = max(dp[i][0], dp[i][1]+p[i+1]-fee);
        int f0 = 0, f1 = INT_MIN/2;
        for (int i = 0; i < n; i++) {
            auto ori_f0 = f0;
            f0 = max(f0, f1+prices[i]-fee);
            f1 = max(f1, ori_f0-prices[i]);
        }
        return f0;
    }
};
// @lc code=end

