/*
 * @lc app=leetcode.cn id=3531 lang=cpp
 *
 * [3531] 统计被覆盖的建筑
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;
        vector<int> l(n+1, INT_MAX);
        vector<int> r(n+1, INT_MIN);
        vector<int> d(n+1, INT_MAX);
        vector<int> u(n+1, INT_MIN);
        for (int i = 0; i < buildings.size(); i++) {
            int x = buildings[i][0], y = buildings[i][1];
            l[x] = min(l[x], y);
            r[x] = max(r[x], y);
            d[y] = min(d[y], x);
            u[y] = max(u[y], x);
        }
        for (int i = 0; i < buildings.size(); i++) {
            int x = buildings[i][0], y = buildings[i][1];
            if (y>l[x]&&y<r[x]&&x>d[y]&&x<u[y]) 
                ans++;
        }
        return ans;
    }
};
// @lc code=end

