/*
 * @lc app=leetcode.cn id=2279 lang=cpp
 *
 * [2279] 装满石头的背包的最大数量
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = capacity[i]-rocks[i];
        }
        ranges::sort(arr);
        for (int i = 0; i < n; i++) {
            if (additionalRocks<arr[i]) {
                return i;
            }
            additionalRocks -= arr[i];
        }
        return n;
    }
};
// @lc code=end

