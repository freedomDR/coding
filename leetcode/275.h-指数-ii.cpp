/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int l = 1, r = len+1;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (citations[len-mid] >= mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l-1;
    }
};
// @lc code=end

