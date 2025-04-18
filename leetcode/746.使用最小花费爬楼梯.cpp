/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() <= 1) return 0;
        int f0 = 0, f1 = 0, f2 = 0;
        for (int i = 2; i <= cost.size(); i++) {
            f2 = min(f0+cost[i-2], f1+cost[i-1]);
            f0 = f1;
            f1 = f2;
        }
        return f2;
    }
};
// @lc code=end

