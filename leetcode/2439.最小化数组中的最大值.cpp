/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 *
 * [2439] 最小化数组中的最大值
 */

// @lc code=start
#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int r = *(ranges::max_element(nums))+1;
        int l = 0;
        auto check = [&](int x) {
            long long extra_add = 0;
            for (int i = nums.size()-1; i >= 0; --i) {
                extra_add = max(0LL, (nums[i] + extra_add) - x);
            }
            return extra_add == 0;
        };
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (!check(mid)) {
                l = mid + 1; 
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

