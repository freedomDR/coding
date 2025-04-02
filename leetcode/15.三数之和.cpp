/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        std::ranges::sort(nums);
        int len = nums.size();
        for (int a = 0; a < len-2; a++) {
            if (a > 0 && nums[a] == nums[a-1])
                continue;
            if (nums[a]+nums[a+1]+nums[a+2]>0)
                break;
            if (nums[a]+nums[len-2]+nums[len-1]<0)
                continue;
            int l = a + 1;
            int r = len - 1;
            while (l < r) {
                int x = nums[a] + nums[l] + nums[r];
                if (x == 0)
                {
                    ans.push_back({nums[a], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l-1]) l++;
                    while (l < r && nums[r] == nums[r+1]) r--;
                }
                else if (x > 0)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};
// @lc code=end
