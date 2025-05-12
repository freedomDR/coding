/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 *
 * [2050] 并行课程 III
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i = 0; i < relations.size(); i++) {
            int from = relations[i][0]-1;
            int to = relations[i][1]-1;
            g[from].push_back(to);
            deg[to]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i]==0)
                q.push(i);
        }
        vector<int> f(n);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            f[x] += time[x];
            //cout << x << " " << f[x] << endl;
            for (auto to:g[x]) {
                f[to] = max(f[to], f[x]);
                if (--deg[to]==0)
                    q.push(to);
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end

