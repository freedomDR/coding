/*
 * @lc app=leetcode.cn id=2944 lang=cpp
 *
 * [2944] 购买水果需要的最少金币数
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<pair<int, int>> dp(n+1, {INT_MAX/2, INT_MAX/2});
        dp[0].first = 0;
        deque<pair<int, int>> min_d;
        for (int i = 1; i <= n; i++) {
            while(!min_d.empty()&&min_d.front().first<(i+1)/2) 
                min_d.pop_front();
            dp[i].second = min(dp[i-1].first, dp[i-1].second) + prices[i-1];
            if (!min_d.empty())
                dp[i].first = min(dp[i].first, min_d.front().second);
            while (!min_d.empty()&&dp[i].second<=min_d.back().second) 
                min_d.pop_back();
            min_d.emplace_back(i, dp[i].second);
            // for (int j = (i+1)/2; j < i; j++) {
            //     dp[i].first = min(dp[i].first, dp[j].second); 
            // }
        }
        return min(dp[n].first, dp[n].second);
    }
};
// @lc code=end

