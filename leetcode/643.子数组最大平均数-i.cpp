/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int ans = -1e7;
        int sums = 0;
        for (int i = 0; i < nums.size(); i++) {
            sums += nums[i];
            if (i>=k-1) {
                ans = max(ans, sums);
                sums -= nums[i-k+1];
            }
        }
        return ans*1.0/k;
    }
};
// @lc code=end

