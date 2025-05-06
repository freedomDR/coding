/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int ans = 0;
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += nums[i];
            int target = tmp-k;
            ans += cnt[target];
            cnt[tmp]++;
        }
        return ans;
    }
};
// @lc code=end

