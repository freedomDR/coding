/*
 * @lc app=leetcode.cn id=2850 lang=cpp
 *
 * [2850] 将石头分散到网格图的最少移动次数
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {

public:
    int minimumMoves(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        vector<pair<int, int>> from, to;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    for (int k = 1; k < grid[i][j]; k++) {
                        from.push_back({i, j});
                    }
                } else {
                    to.push_back({i, j});
                }
            }
        }
        do {
            int cnt = 0;
            for (int i = 0; i < from.size(); i++) {
                cnt += abs(from[i].first - to[i].first) + abs(from[i].second - to[i].second);
            }
            ans = min(ans, cnt);
        } while(next_permutation(from.begin(), from.end()));
        return ans;
    }
};
// @lc code=end

