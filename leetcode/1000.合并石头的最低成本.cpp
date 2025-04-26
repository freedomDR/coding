/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n-1)%(k-1)!=0) return -1;
        vector<int> prefix(n+1);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + stones[i];
        }
        vector<vector<int>> dp(n+1, vector<int>(n+1, INT_MAX));
        for (int i = 0; i < n; i++) dp[i][i] = 0;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i+len-1 < n; i++) {
                int j = i+len-1;
                for (int m = i; m < j; m += k-1) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m+1][j]);
                }
                if ((j-i)%(k-1)==0) {
                    dp[i][j] += prefix[j+1] - prefix[i];
                }
            }
        }
        return dp[0][n-1];
    }
};
// @lc code=end

