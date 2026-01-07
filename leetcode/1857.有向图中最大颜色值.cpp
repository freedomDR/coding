/*
 * @lc app=leetcode.cn id=1857 lang=cpp
 *
 * [1857] 有向图中最大颜色值
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (auto arr:edges) {
            int u = arr[0], v = arr[1];
            g[u].push_back(v);
            deg[v]++;
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26));
        for (int i = 0; i < n; i++) {
            if (deg[i]==0) {
                q.push(i);
                int x = colors[i]-'a';
                dp[i][x]++;
            }
        }
        int vis = 0;
        int ans = 1;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            vis++;
            for (int u:g[i]) {
                if (--deg[u]==0) q.push(u);
                int x = colors[u]-'a';
                for (int p = 0; p < 26; p++) {
                    dp[u][p] = max(dp[u][p], dp[i][p] + (p==x));
                    ans = max(ans, dp[u][p]);
                }
            }
        }
        return vis==n?ans:-1;

    }
};
// @lc code=end

