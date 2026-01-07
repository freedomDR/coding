/*
 * @lc app=leetcode.cn id=2090 lang=cpp
 *
 * [2090] 半径为 k 的子数组平均值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += nums[i];
            if (i>=2*k) {
                int pos = i-k;
                ans[pos] = tmp/(2*k+1);
                tmp -= nums[i-2*k];
            }
        }
        return ans;
    }
};
// @lc code=end

