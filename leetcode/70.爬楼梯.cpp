/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int f0 = 1, f1 = 1, f2;
        for (int i = 2; i <= n; i++) {
            f2 = f1+f0;
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};
// @lc code=end

