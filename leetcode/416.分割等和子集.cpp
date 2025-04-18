/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sums = accumulate(nums.begin(), nums.end(), 0);
        if (sums % 2 != 0) {
            return false;
        }
        auto target = sums/2;
        vector<bool> f(target+1);
        f[0] = true;
        for (auto num : nums) {
            for (int j = target; j >= num; --j) {
                f[j] = f[j] || f[j - num];
            }
        }
        return f[target];
    }
};
// @lc code=end

