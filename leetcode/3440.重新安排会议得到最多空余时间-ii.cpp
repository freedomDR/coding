/*
 * @lc app=leetcode.cn id=3440 lang=cpp
 *
 * [3440] 重新安排会议得到最多空余时间 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int ans = 0;
        int pre = 0;
        for (int i = 0; i < startTime.size(); i++) {
            int cur = 0;
            if (i == 0) cur = startTime[i]-0;
            else cur = startTime[i]-endTime[i-1];
            ans = max(ans, pre+cur);
            pre = cur;
        }
        ans = max(ans, pre+(eventTime-endTime.back()));
        return ans;
    }
};
// @lc code=end

