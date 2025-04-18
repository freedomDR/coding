/*
 * @lc app=leetcode.cn id=2787 lang=cpp
 *
 * [2787] 将一个数字表示成幂的和的方案数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9+7;
        int max_n = 1;
        while (pow(max_n, x) <= n) {
            max_n++;
        }
        vector<int> f(n+1, 0);
        f[0] = 1;
        for (int i = 1; i < max_n; i++) {
            for (int j = n; j >= pow(i, x); j--) {
                f[j] = (f[j] + f[j - pow(i, x)]) % MOD;
            }
        }
        return f[n];
    }
};
// @lc code=end

