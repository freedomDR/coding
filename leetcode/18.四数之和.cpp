/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        vector<vector<int>> ans;
        ranges::sort(nums);
        int len = nums.size();
        for (int a = 0; a < len - 3; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            if (0L+nums[a] + nums[a + 1] + nums[a + 2] + nums[a + 3] > target)
                break;
            if (0L+nums[a] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target)
                continue;
            for (int b = a + 1; b < len - 2; b++) {
                if (b > a+1 && nums[b] == nums[b-1]) continue;
                if (0L+nums[a]+nums[b]+nums[b+1]+nums[b+2] > target) break;
                if (0L+nums[a]+nums[b]+nums[len-1]+nums[len-2] < target) continue;
                int l = b + 1, r = len - 1;
                while (l < r) {
                    long long tmp_sum =
                        0L + nums[a] + nums[b] + nums[l] + nums[r];
                    if (tmp_sum == target) {
                        ans.push_back({nums[a], nums[b], nums[l++], nums[r--]});
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    } else if (tmp_sum > target)
                        r--;
                    else
                        l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
