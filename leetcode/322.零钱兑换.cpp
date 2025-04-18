/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i][c] = min(dp[i-1][c], dp[i][c-coins[i]] + 1)
        vector<int> f(amount+1, 1e5);
        f[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                f[j] = min(f[j], f[j - coins[i]] + 1);
            }
        }
        return f[amount] >= 1e5 ? -1 : f[amount];
    }
};
// @lc code=end

