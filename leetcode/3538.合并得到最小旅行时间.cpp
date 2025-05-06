/*
 * @lc app=leetcode.cn id=3538 lang=cpp
 *
 * [3538] 合并得到最小旅行时间
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int minTravelTime(int l, int n, int k, vector<int>& position, vector<int>& time) {
        // solution 1
        // vector<vector<vector<int>>> cache(k+1, vector<vector<int>>(n, vector<int>(n)));
        // vector<int> prefix_time(n+1);
        // for (int i = 0; i < n; i++) prefix_time[i+1] = prefix_time[i]+time[i];
        // auto dfs = [&](this auto && self, int remain, int i, int pre) -> int {
        //     if (i == n-1)
        //         return remain?INT_MAX/2:0;
        //     int & res = cache[remain][i][pre];
        //     if (res) return res;
        //     res = INT_MAX;
        //     int t = prefix_time[i+1]-prefix_time[pre];
        //     for (int nxt = i+1; nxt < min(n, i+1+remain+1); nxt++) {
        //         res = min(res, self(remain-(nxt-i-1), nxt, i+1)+(position[nxt]-position[i])*t);
        //     }
        //     return res;
        // };
        // return dfs(k, 0, 0);

        // solution 2
        vector<int> prefix_time(n+1);
        for (int i = 0; i < n; i++) prefix_time[i+1] = prefix_time[i]+time[i];
        vector dp(k+1, vector(n, vector<int>(n, INT_MAX/2)));
        for (int i = 0; i < n; i++) dp[0][n-1][i] = 0;
        for (int kk = 0; kk <= k; kk++) {
            for (int i = n-1; i >= 0; i--) {
                for (int pre = i; pre >= 0; pre--) {
                    int t = prefix_time[i+1]-prefix_time[pre];
                    for (int nxt = i+1; nxt < min(n, i+1+kk+1); nxt++) {
                        dp[kk][i][pre] = min(dp[kk][i][pre], dp[kk-(nxt-i-1)][nxt][i+1]+(position[nxt]-position[i])*t);
                    }
                }
            }
        } 
        return dp[k][0][0];
    }
};
// int main()
// {
//     vector<int> pos = {0,3,8,10}, time = {5,8,3,6};
//     Solution s;
//     cout << s.minTravelTime(10, 4, 1, pos, time);
//     return 0;
// }
// @lc code=end

