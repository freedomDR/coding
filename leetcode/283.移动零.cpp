/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // solution 1
        // int l = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i]) {
        //         nums[l++] = nums[i];
        //     }
        // }
        // while (l < nums.size()) {
        //     nums[l++] = 0;
        // }

        // solution 2
        // int i0 = 0;
        // for (int & x:nums) {
        //     if (x) {
        //         swap(x, nums[i0]);
        //         i0++;
        //     }
        // }

        // solution 3
        int i0 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                if (i > i0) {
                    nums[i0] = nums[i];
                    nums[i] = 0;
                }
                i0++;
            }
        }
    }
};
// @lc code=end

