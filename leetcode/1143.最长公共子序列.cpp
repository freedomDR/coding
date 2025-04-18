/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> dp(m+1, 0);
        for (int i = 1; i <= n; i++) {
            int prev = 0;
            for (int j = 1; j <=m; j++) {
                auto tmp = dp[j];
                if (text1[i-1] == text2[j-1]) {
                    dp[j] = prev+1;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                prev = tmp;
            }
        }
        return dp[m];
    }
};
// @lc code=end

