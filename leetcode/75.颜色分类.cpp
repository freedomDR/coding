/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int p0 = 0, p1 = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     int x = nums[i];
        //     nums[i] = 2;
        //     if (x<=1) {
        //         nums[p1++] = 1;
        //     }
        //     if (x==0) {
        //         nums[p0++] = 0;
        //     }
        // }

        int n = nums.size();
        int l = 0, r = n-1, i = 0;
        while (i<=r) {
            if (nums[i]==0) swap(nums[l++], nums[i++]);
            else if (nums[i]==1) i++;
            else swap(nums[i], nums[r--]);
        }
    }
};
// @lc code=end

