/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
         vector<unsigned> f(amount+1, 0);
         f[0] = 1;
         for (auto coin:coins) {
            for (int j = coin; j <= amount; j++) {
                f[j] = f[j] + f[j-coin];
            }
         }
         return f[amount];
    }
};
// @lc code=end

