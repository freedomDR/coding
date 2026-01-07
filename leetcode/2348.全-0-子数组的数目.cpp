/*
 * @lc app=leetcode.cn id=2348 lang=cpp
 *
 * [2348] 全 0 子数组的数目
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // trick
        nums.push_back(1);
        long long ans = 0;
        int zeros = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]!=0) {
                if (zeros>0) {
                    ans += 1ll*(1+zeros)*zeros/2;
                    zeros=0;
                }
            } else {
                zeros++;
            }
        }
        return ans;
    }
};
// @lc code=end

