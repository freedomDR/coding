/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        // vector<vector<int>> cache(n + 1, vector<int>(n + 1, 0));
        // function<int(int, int)> dfs = [&](int l, int r) -> int {
        //     if (l>=r) return 0;
        //     auto & res = cache[l][r];
        //     if (res) return res;
        //     res = INT_MAX;
        //     for (int i = l; i <= r; i++) {
        //         res = min(res, i+max(dfs(l, i-1), dfs(i+1, r)));
        //     }
        //     return res;
        // };
        // return dfs(1, n);

        // dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i+1; j <= n; j++) {
                dp[i][j] = INT_MAX/2;
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

