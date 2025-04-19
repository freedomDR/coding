/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> f(n, 1), g(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (f[i] < f[j] +1) {
                        f[i] = f[j] + 1;
                        g[i] = g[j];
                    } else if (f[i] == f[j] + 1) {
                        g[i] += g[j];
                    }
                }
            }
        }
        int max_len = *max_element(f.begin(), f.end());
        for (int i = 0; i < n; i++) {
            if (f[i] == max_len) {
                ans += g[i];
            }
        }
        return ans;
    }
};
// @lc code=end

