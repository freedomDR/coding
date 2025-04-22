/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // 1
        // string ss = s;
        // reverse(ss.begin(), ss.end());
        // dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j], dp[i][j]+(s[i]==ss[j]))
        // int n = s.size();
        // vector<vector<int>> dp(2, vector<int>(n+1, 0));
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         dp[(i+1)%2][j+1] = max({dp[i%2][j+1], dp[(i+1)%2][j], dp[i%2][j]+(s[i]==ss[j])});
        //     }
        // }
        // return dp[(n)%2][n];
        // vector<int> dp(n+1, 0);
        // for (int i = 0; i < n; i++) {
        //     int pre = 0;
        //     for (int j = 0; j < n; j++) {
        //         auto tmp = dp[j+1];
        //         dp[j+1] = max({dp[j], dp[j+1], pre+(s[i]==ss[j])}); 
        //         pre = tmp;
        //     }
        // }
        // return dp[n];
        
        // 递归
        // int n = s.size();
        // vector<vector<int>> cache(n, vector<int>(n, -1));
        // auto dfs = [&](this auto && dfs, int l, int r) -> int {
        //     if (l > r) return 0;
        //     if (l == r) return 1;
        //     auto & res = cache[l][r];
        //     if (res != -1) return res;
        //     return res = max({dfs(l+1, r), dfs(l, r-1), dfs(l+1, r-1)+(s[l]==s[r]? 2: 0)});
        // };
        // return dfs(0, n-1);

        // dp
        int n = s.size(); 
        // dp[i][j] = max(dp[i+1][j], dp[i][j-1], dp[i+1][j-1]+(s[i]==s[j]?2:0))
        // j = j-1 dp[i][j+1] = max(dp[i+1][j+1], dp[i][j], dp[i+1][j]+(s[i]==s[j]?2:0))
        vector<int> dp(n+1, 1);
        for (int i = n-1; i >= 0; i--) {
            int pre = 0;
            for (int j = i+1; j < n; j++) {
                auto tmp = dp[j+1];
                dp[j+1] = max({dp[j], dp[j+1], pre+(s[i]==s[j]?2:0)});
                pre = tmp;
            }
        }
        return dp[n];
    }
};
// @lc code=end

