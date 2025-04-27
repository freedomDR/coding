/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 *
 * [1547] 切棍子的最小成本
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        ranges::sort(cuts);

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m));
        // dp[i][j] = dp[i][k]+dp[k][j] + c[j]-c[i]
        for (int i = m-3; i >= 0; i--) {
            for (int j = i+2; j < m; j++) {
                int tmp = INT_MAX;
                for (int k = i+1; k < j; k++) {
                    tmp = min(tmp, dp[i][k]+dp[k][j]);
                }
                dp[i][j] = tmp + cuts[j]-cuts[i];
            }
        }
        return dp[0][m-1];
    }
};
// @lc code=end

