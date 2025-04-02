/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */

// @lc code=start
#include <algorithm>
class Solution {
   public:
    int countPairs(vector<int>& nums, int target) {
        std::ranges::sort(nums);
        int ans = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l]+nums[r] >= target) {
                r--;
            } else {
                ans += (r-l);
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end
