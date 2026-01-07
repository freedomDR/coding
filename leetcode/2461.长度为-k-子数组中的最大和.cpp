/*
 * @lc app=leetcode.cn id=2461 lang=cpp
 *
 * [2461] 长度为 K 子数组中的最大和
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long sums = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            sums += x;
            mp[x]++;
            if (i>=k-1) {
                if (mp.size()==k) ans = max(ans, sums);
                int y = nums[i-k+1];
                sums -= y;
                if (--mp[y] == 0) mp.erase(y);
            }
        }
        return ans;
    }
};
// @lc code=end

