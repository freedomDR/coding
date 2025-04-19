/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size(), k = s3.size();
        if (n+m!=k) return false;
        if (n==0||m==0) 
            return s1==s3||s2==s3;
        // dp[i][j] |= (s3[i+j-2]==s1[i-1] && dp[i-1][j]) || (s3[i+j-2]==s2[j-1] && dp[i][j-1]);
        vector<bool> dp(m+1, false);
        dp[0] = true;
        for (int i = 1; i <=m; i++) dp[i] = s3[i-1]==s2[i-1] && dp[i-1];
        for (int i = 1; i <= n; i++) {
            dp[0] = s3[i-1]==s1[i-1] && dp[0];
            for (int j = 1; j <= m; j++) {
                dp[j] = (s3[i+j-1]==s1[i-1] && dp[j]) || (s3[i+j-1]==s2[j-1] && dp[j-1]);
            }
        }
        return dp[m];
    }
};
// @lc code=end

