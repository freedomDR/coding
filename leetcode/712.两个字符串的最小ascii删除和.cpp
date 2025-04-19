/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // dp[i][j] = s1[i-1]==s[j-1] ? dp[i-1][j-1] : min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1])
        int n = s1.size(), m = s2.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= m; i++) dp[i] = dp[i - 1] + s2[i - 1];
        for (int i = 1; i <= n; i++) {
            auto pre = dp[0];
            dp[0] += s1[i - 1];
            for (int j = 1; j <= m; j++) {
                auto tmp = dp[j];
                dp[j] = s1[i - 1] == s2[j - 1] ? pre : min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                pre = tmp;
            }
        }
        return dp[m];
    }
};
// @lc code=end

