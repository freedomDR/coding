/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int max_v = (int)sqrt(n) + 1;
        vector<int> f(n+1, 1e5);
        f[0] = 0;
        for (int i = 1; i <= max_v; i++) {
            for (int j = i*i; j <= n; j++) {
                f[j] = min(f[j], f[j-i*i]+1);
            }
        }
        return f[n];
    }
};
// @lc code=end

