/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        // int n = s.size();
        // vector<vector<int>> cache(n, vector<int>(n, -1));
        // auto dfs = [&](this auto && self, int l, int r) -> int {
        //     if (l >= r) return 0;
        //     auto & res = cache[l][r];
        //     if (res != -1) return res;
        //     if (s[l]==s[r]) return res = self(l+1, r-1);
        //     return res = min(self(l+1, r), self(l, r-1)) + 1;
        // };
        // return dfs(0, n-1);

        // dp[i][j] = dp[i+1][j-1] if s[i] == s[j]
        // dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1 if s[i] != s[j]
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1];
                } else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

