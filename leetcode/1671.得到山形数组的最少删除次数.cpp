/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1), dp2(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++ ) {
                if (nums[i] > nums[j]) {
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
            }
        }
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j > i; j-- ) {
                if (nums[i] > nums[j]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 1; i < n-1; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                ans = max(ans, dp1[i] + dp2[i] - 1);
            }
        }
        return n - ans;
    }
};

// int main()
// {
//     Solution s;
//     vector<int> nums = {100,92,89,77,74,66,64,66,64};
//     cout << s.minimumMountainRemovals(nums) << endl;
//     return 0;
// }
// @lc code=end

