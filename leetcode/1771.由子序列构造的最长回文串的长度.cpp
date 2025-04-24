/*
 * @lc app=leetcode.cn id=1771 lang=cpp
 *
 * [1771] 由子序列构造的最长回文串的长度
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        // cacb abbc
        string s = word1 + word2;
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // dp[i][j] = max(dp[i+1][j], dp[i][j-1], dp[i+1][j-1]+(s[i]==s[j]?2:0))
        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                    if (i < word1.size() && j >= word1.size()) {
                        ans = max(ans, dp[i][j]);
                    }
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

