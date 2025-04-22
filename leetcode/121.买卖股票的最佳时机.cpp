/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_v = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            ans = max(ans, prices[i]-min_v);
            min_v = min(min_v, prices[i]);
        }
        return ans;
    }
};
// @lc code=end

