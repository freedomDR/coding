/*
 * @lc app=leetcode.cn id=1964 lang=cpp
 *
 * [1964] 找出到每个位置为止最长的有效障碍赛跑路线
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> ans(n, 0);
        vector<int> f;
        for (int i = 0; i < n; i++) {
            int x = obstacles[i];
            auto it = upper_bound(f.begin(), f.end(), x);
            ans[i] = it-f.begin() + 1;
            if (it == f.end()) {
                f.push_back(x);
            } else {
                *it = x;
            }
        }
        return ans;
    }
};
// @lc code=end

