/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] 最大交替子序列和
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<long long>> cache(n, vector<long long>(2, LONG_LONG_MIN/2));
        // auto dfs = [&](this auto && dfs, int pos, int is_even) -> long long {
        //     if (pos < 0) return 0;
        //     auto & res = cache[pos][is_even];
        //     if (res != LONG_LONG_MIN/2)
        //         return res;
        //     if (is_even) 
        //         return res = max(dfs(pos-1, 1), dfs(pos-1, 0)+nums[pos]);
        //     return res = max(dfs(pos-1, 0), dfs(pos-1, 1)-nums[pos]);
        // };
        // return dfs(n-1, 1);

        int n = nums.size();
        // dp[i+1][0] = max(dp[i][0], dp[i][1]-nums[pos])
        // dp[i+1][1] = max(dp[i][1], dp[i][0]+nums[pos])
        long long f0 = 0, f1 = 0;
        for (int i = 0; i < n; i++) {
            auto ori_f0 = f0;
            f0 = max(f0, f1-nums[i]);
            f1 = max(f1, ori_f0+nums[i]);
        }
        return f1;
    }
};
// @lc code=end

