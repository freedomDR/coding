/*
 * @lc app=leetcode.cn id=2094 lang=cpp
 *
 * [2094] 找出 3 位偶数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> ans;
        int n = digits.size();
        vector<bool> vis(n, false);
        auto dfs = [&](this auto && self, int v, int len) {
            if (len == 3) {
                if (v%2==0)
                    ans.insert(v);
                return;
            }
            for (int i = 0; i < digits.size(); i++) {
                if (vis[i]) continue;
                if (len>0||(digits[i]!=0)) {
                    vis[i] = true;
                    self(v*10+digits[i], len+1);
                    vis[i] = false;
                }
            }
        };
        dfs(0, 0);
        return {ans.begin(), ans.end()};
    }
};
// @lc code=end

