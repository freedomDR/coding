/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        // int n = values.size();
        // vector<vector<int>> cache(n, vector<int>(n, -1));
        // auto dfs = [&](this auto && dfs, int l, int r) -> int {
        //     if (r-l<2) return 0;
        //     if (r-l==2) return values[l]*values[l+1]*values[r];
        //     auto & res = cache[l][r];
        //     if (res != -1) return res;
        //     res = INT_MAX;
        //     for(int i = l+1; i < r; i++) {
        //         res = min(res, dfs(l, i)+dfs(i, r)+values[l]*values[i]*values[r]);
        //     }
        //     return res;
        // };
        // return dfs(0, n-1);

        // dp[i][j] = min dp[i][k]+dp[k][j]+values[i]*values[k]*values[j]
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n-1; i >= 0; i--) {
            for (int j = i+2; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i+1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+values[i]*values[k]*values[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

