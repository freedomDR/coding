/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] 几乎唯一子数组的最大和
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0;
        long long sums = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            sums += nums[i];
            mp[nums[i]]++;
            if (i>=k-1) {
                if (mp.size()>=m) ans = max(ans, sums);
                sums -= nums[i-k+1];
                mp[nums[i-k+1]]--;
                if (mp[nums[i-k+1]]==0)
                    mp.erase(nums[i-k+1]);
            }
        }
        return ans;
    }
};
// @lc code=end

