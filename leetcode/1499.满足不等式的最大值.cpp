/*
 * @lc app=leetcode.cn id=1499 lang=cpp
 *
 * [1499] 满足不等式的最大值
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        int n = points.size();
        deque<pair<int, int>> max_d;
        for (int i = 0; i < n; i++) {
            int x = points[i][0], y = points[i][1];
            while (!max_d.empty()&&x-max_d.front().first>k)
                max_d.pop_front();
            if (!max_d.empty())
                ans = max(ans, x+y+max_d.front().second);
            while (!max_d.empty()&&y-x>=max_d.back().second)
                max_d.pop_back();
            max_d.emplace_back(x,y-x);
        }
        return ans; 
    }
};
// @lc code=end

