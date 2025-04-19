/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j] = word1[i-1] == word2[j-1] ? dp[i-1][j-1] : min(dp[i-1][j]+1, dp[i][j-1]+1);
        // dp[i+1][j+1] = word1[i] == word2[j] ? dp[i][j] : min(dp[i][j+1]+1, dp[i+1][j]+1);      
        int n = word1.size(), m = word2.size();
        vector<int> dp(m + 1, 0);
        for (int j = 1; j <= m; j++) dp[j] = j;
        for (int i = 1; i <= n; i++) {
            // dp[i][0] = i;
            dp[0] = i;
            int pre = i-1;
            for (int j = 1; j <= m; j++) {
                int tmp = dp[j];
                dp[j] = word1[i - 1] == word2[j - 1] ? pre : min(dp[j - 1] + 1, dp[j]+1);
                pre = tmp;
            }
        }
        return dp[m];
    }
};
// @lc code=end

