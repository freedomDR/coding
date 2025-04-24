/*
 * @lc app=leetcode.cn id=3040 lang=cpp
 *
 * [3040] 相同分数的最大操作数目 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> cache(n, vector<int>(n, -1));
        // function<int(int, int, int)> dfs = [&](int l, int r, int pre) -> int {
        //     if (l >= r) return 0;
        //     auto & res = cache[l][r];
        //     if (res != -1) return res;
        //     res = 0;
        //     if (nums[l]+nums[l+1]==pre)
        //         res = max(res, 1+dfs(l+2, r, pre));
        //     if (nums[l]+nums[r]==pre)
        //         res = max(res, 1+dfs(l+1, r-1, pre));
        //     if (nums[r-1]+nums[r]==pre)
        //         res = max(res, 1+dfs(l, r-2, pre));
        //     return res;
        // };
        // return 1+max({
        //     dfs(2, n-1, nums[0]+nums[1]),
        //     dfs(1, n-2, nums[0]+nums[n-1]),
        //     dfs(0, n-3, nums[n-2]+nums[n-1]),
        // });

        // dp[i][j] = max(dp[i+1][j-1], dp[i+2][j], dp[i][j-2])
        // dp[i][j+1] = max(dp[i+1][j], dp[i+1][j-1], dp[i][j-1])
        int n = nums.size();
        auto res = [&](int l, int r, int pre) -> int {
            vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
            for (int i = r-1; i >= l; i--) {
                for (int j = i+1; j <= r; j++) {
                    if (nums[i]+nums[j]==pre)
                        dp[i][j+1] = max(dp[i][j+1], 1+dp[i+1][j]);
                    if (nums[i]+nums[i+1]==pre)
                        dp[i][j+1] = max(dp[i][j+1], 1+dp[i+2][j+1]);
                    if (nums[j-1]+nums[j]==pre)
                        dp[i][j+1] = max(dp[i][j+1], 1+dp[i][j-1]);
                }
            }
            return dp[l][r+1];
        };
        return 1+max({
            res(2, n-1, nums[0]+nums[1]),
            res(1, n-2, nums[0]+nums[n-1]),
            res(0, n-3, nums[n-2]+nums[n-1]),
        });
    }
};
// @lc code=end

