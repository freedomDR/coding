/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // a+b>c
        // a<b<c
        long long ans = 0;
        ranges::sort(nums);
        int len = nums.size();
        for (int i = len-1; i > 1; i--) {
            if (nums[i-1]+nums[i-2]<=nums[i]) continue;
            if (nums[0]+nums[1]>nums[i])
            {
                // (i+1)!/(3)!/(i+1-3)! = (i+1) * (i) * (i-1)/6
                ans += 1L*(i+1)*i*(i-1)/6;
                break;
            }
            int l = 0, r = i-1;
            while (l < r) {
                int tmp = nums[l] + nums[r];
                if (tmp > nums[i]) {
                    ans += r-l;
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

