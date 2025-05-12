/*
 * @lc app=leetcode.cn id=2918 lang=cpp
 *
 * [2918] 数组的最小相等和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0, zero2 = 0;
        ll sums1 = 0, sums2 = 0;
        for (auto v:nums1) {
            sums1 += v;
            zero1 += (v==0);
        }
        for (auto v:nums2) {
            sums2 += v;
            zero2 += (v==0);
        }
        if (zero1+zero2==0) {
            return (sums1==sums2?(sums1):-1);
        } else if (zero1==0) {
            return (sums2+zero2)<=sums1?(sums1):-1;
        } else if (zero2==0) {
            return (sums1+zero1)<=sums2?(sums2):-1;
        } else {
            return max(sums1+zero1, sums2+zero2);
        }
    }
};
// @lc code=end

