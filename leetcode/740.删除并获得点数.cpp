/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cctype>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num] += num;
        }
        vector<int> dp(10001, 0);
        dp[1] = m[1];
        for (int i = 2; i < 10001; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + m[i]);
        }
        return dp[10000];
    }
};
// @lc code=end

