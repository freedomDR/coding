/*
 * @lc app=leetcode.cn id=1920 lang=cpp
 *
 * [1920] 基于排列构建数组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        // vector<int> ans;
        // for (int i = 0; i < nums.size(); i++) {
        //     ans.push_back(nums[nums[i]]);
        // }
        // return ans;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (x < 0) continue;
            int cur = i;
            while (nums[cur] != i) {
                int b = nums[cur];
                nums[cur] = ~nums[b];
                cur = b;
            }
            nums[cur] = ~x;
        }
        for (int i = 0; i < nums.size(); i++) 
            nums[i] = ~nums[i];
        return nums;
    }
};
// @lc code=end

