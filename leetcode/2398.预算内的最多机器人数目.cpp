/*
 * @lc app=leetcode.cn id=2398 lang=cpp
 *
 * [2398] 预算内的最多机器人数目
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int ans = 0;
        int n = chargeTimes.size();
        deque<int> d;
        long long sums = 0;
        int l = 0;
        for(int i = 0; i < n; i++) {
            while(!d.empty()&&chargeTimes[i]>=chargeTimes[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
            sums += runningCosts[i];
            while (l<=i && sums*(i-l+1)+chargeTimes[d.front()] > budget) {
                if (l == d.front()) d.pop_front();
                sums -= runningCosts[l++];
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
// @lc code=end

