/*
 * @lc app=leetcode.cn id=3341 lang=cpp
 *
 * [3341] 到达最后一个房间的最少时间 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        int ans = INT_MAX;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        auto dfs = [&](this auto && self, int x, int y, int v) {
            if (x == n-1 && y == m-1) {
                ans = min(ans, v);
                return;
            }
            if (v >= ans) return;
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if (nx>=n||ny>=m||nx<0||ny<0) continue;
                int nxt_cost = max(v+1, moveTime[nx][ny]+1);
                if (dis[nx][ny] <= nxt_cost) continue;
                dis[nx][ny] = nxt_cost;
                self(nx, ny, nxt_cost);
            }
        };
        dis[0][0] = 0;
        dfs(0, 0, 0);
        return ans;
    }
};
// int main()
// {
//     Solution s;
//     vector<vector<int>> arr = {{0, 4}, {4, 4}};
//     cout << s.minTimeToReach(arr) << endl;
//     return 0;
// }
// @lc code=end

