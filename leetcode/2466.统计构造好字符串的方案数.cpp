/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1e9+7;
        int ans = 0;
        vector<int> f(high+1, 0);
        f[0] = 1;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) f[i] = f[i-zero];
            if (i >= one) f[i] = (f[i]+f[i-one])%mod;
            if (i >= low) ans = (ans+f[i])%mod;
        }
        return ans;
    }
};
// @lc code=end

