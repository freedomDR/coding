/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
#include <bits/stdc++.h>
#include <deque>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1;
        deque<int> d;
        for (int v:nums) {
            while (!d.empty() && d.back()>=v)  {
                d.pop_back();
            }
            d.push_back(v);
            if (d.size() > 1)
                ans = max(ans, d.back()-d.front());
        }
        return ans;
    }
};
// @lc code=end

