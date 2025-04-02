/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        nums.push_back(INT_MIN);
        int l = 0, r = len;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] < nums[mid+1]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        return l;        
    }
};
// @lc code=end

