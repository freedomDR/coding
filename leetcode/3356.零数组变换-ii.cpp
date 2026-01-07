/*
 * @lc app=leetcode.cn id=3356 lang=cpp
 *
 * [3356] 零数组变换 II
 */

// @lc code=start
#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if (accumulate(nums.begin(), nums.end(), 0ll) == 0) {
            return 0;
        }
        int l = 0, r = queries.size();
        int n = nums.size();
        while (l < r) {
            int mid = l+(r-l)/2;
            vector<int> f(n+1);
            for (int i = 0; i < mid+1; i++) {
                int left = queries[i][0];
                int right = queries[i][1];
                int v = queries[i][2];
                f[left] += v;
                f[right+1] -= v;
            }
            bool ok = true;
            int tmp = 0;
            for (int i = 0; i < n; i++) {
                tmp += f[i];
                if (tmp < nums[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return r==queries.size()?-1:r+1;
    }
};
// @lc code=end

