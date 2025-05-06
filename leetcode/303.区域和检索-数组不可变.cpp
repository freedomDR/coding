/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n+1);
        for (int i = 0; i < n; i++) 
            prefix[i+1] = prefix[i]+nums[i];
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

