/*
 * @lc app=leetcode.cn id=1438 lang=cpp
 *
 * [1438] 绝对差不超过限制的最长连续子数组
 */

// @lc code=start
#include <bits/stdc++.h>
#include <deque>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_d, min_d;
        int n = nums.size();
        int ans = 0, l = 0;
        for (int i = 0; i < n; i++) {
            while(!max_d.empty()&&nums[i]>=nums[max_d.back()]) {
                max_d.pop_back();
            }
            max_d.push_back(i);
            while(!min_d.empty()&&nums[i]<=nums[min_d.back()]) {
                min_d.pop_back();
            }
            min_d.push_back(i);
            while (nums[max_d.front()]-nums[min_d.front()]>limit) {
                if (max_d.front()==l) max_d.pop_front();
                if (min_d.front()==l) min_d.pop_front();
                l++;
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
// @lc code=end

