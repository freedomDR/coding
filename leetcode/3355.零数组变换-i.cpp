/*
 * @lc app=leetcode.cn id=3355 lang=cpp
 *
 * [3355] 零数组变换 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> f(n+1);
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0], r = queries[i][1];
            f[l]++;
            f[r+1]--;
        }
        int tmp_sums = 0;
        for (int i = 0; i < n; i++) {
            tmp_sums += f[i];
            if (nums[i]>tmp_sums) return false; 
        }
        return true;
    }
};
// @lc code=end

