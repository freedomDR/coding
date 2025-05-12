/*
 * @lc app=leetcode.cn id=3342 lang=cpp
 *
 * [3342] 到达最后一个房间的最少时间 II
 */

// @lc code=start
#include <bits/stdc++.h>
#include <functional>
#include <queue>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX/2));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(0, 0, 0);
        dis[0][0] = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        while(!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (x==n-1 && y==m-1) {
                return d;
            }
            if (d > dis[x][y]) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x+dx[i], ny = y+dy[i];
                if (nx>=0&&nx<n&&ny>=0&&ny<m) {
                    int nd = max(d, moveTime[nx][ny]) + (x+y)%2+1;
                    if (nd < dis[nx][ny]) {
                        dis[nx][ny] = nd;
                        pq.emplace(nd, nx, ny);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

