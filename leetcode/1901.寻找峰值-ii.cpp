/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int l = 0, r = m;
        auto max_v = [&](int pos)
        {
            if (pos == m)
                return -1;
            return *(ranges::max_element(mat[pos]));
        };
        while (l < r) {
            int mid = l + (r-l)/2;
            if (max_v(mid) < max_v(mid+1)) {
                l = mid+1;
            } else {
                r = mid;
            }
        }

        return {l, (int)distance(mat[l].begin(), ranges::max_element(mat[l]))};
    }
};
// @lc code=end

