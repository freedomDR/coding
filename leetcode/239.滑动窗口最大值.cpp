/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <bits/stdc++.h>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> d;
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            while(!d.empty()&&nums[i]>=nums[d.back()]) {
                auto p = d.back();
                d.pop_back();
            }
            d.push_back(i);
            while(d.back()-d.front()+1>k)
                d.pop_front();
            if (i >= k-1) 
                ans.push_back(nums[d.front()]);
        }
        return ans;

    }
};
// @lc code=end

