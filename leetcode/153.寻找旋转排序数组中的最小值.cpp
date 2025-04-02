/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] > nums[len-1]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return nums[min(l, len-1)];
    }
};
// @lc code=end

