/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])
        int n = prices.size();
        int f0 = 0, f1 = INT_MIN, f00 = 0;
        for (int i = 0; i < n; i++) {
            int ori_f0 = f0;
            f0 = max(f0, f1+prices[i]);
            f1 = max(f1, f00-prices[i]);
            f00 = ori_f0;
            //cout << i << ": " << f0 << " " << f1 << "---" << f00 << endl;
        }
        return f0;
    }
};

// int main()
// {
//     Solution s;
//     vector<int> arr = {1,2,3,0,2};
//     cout << s.maxProfit(arr) << endl;
//     return 0;
// }
// @lc code=end

