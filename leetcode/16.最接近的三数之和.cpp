/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <algorithm>
#include <cstdint>
#include <vector>
class Solution {
   public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int ans = INT32_MAX/2;
        std::ranges::sort(nums);
        int len = nums.size();
        for (int i = 0; i < len-2; i++) {
            int l = i+1, r = len-1;
            long long tmp1 = nums[i]+nums[i+1]+nums[i+2];
            if (tmp1 > target && (tmp1-target) > abs(ans-target))
                break;
            long long tmp2 = nums[i]+nums[len-1]+nums[len-2];
            if (tmp2 < target && (target-tmp2) > abs(ans-target))
                continue;
            while (l < r) {
                long long x = nums[i] + nums[l] + nums[r];
                if (x == target)
                    return target;
                if (x > target) {
                    r--;
                } else {
                    l++;
                }
                if (std::abs(x-target) < abs(ans-target))
                    ans = x;
            }
        }
        return ans;
    }
};
// @lc code=end
