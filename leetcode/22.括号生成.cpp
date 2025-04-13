/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        auto dfs1 = [&](this auto && self, int left, int right) -> void {
            if (left == n && right == n) {
                ans.push_back(s);
                return;
            }
            if (left < n) {
                s.push_back('(');
                self(left + 1, right);
                s.pop_back();
            }
            if (right < left) {
                s.push_back(')');
                self(left, right + 1);
                s.pop_back();
            }
        };
        // dfs1(0, 0);
        vector<int> right_p;
        auto dfs2 = [&](this auto && self, int pos) {
            if (right_p.size() == n) {
                string s(n * 2, '(');
                for (int i = 0; i < n; ++i) {
                    s[right_p[i]] = ')';
                }
                ans.push_back(s);
                return;
            }
            int right_p_size = right_p.size();
            for (int i = pos; i < n*2; i++) {
                if ((right_p_size+1)*2>i+1) continue;
                right_p.push_back(i);
                self(i + 1);
                right_p.pop_back();
            }
        };
        dfs2(0);
        return ans;
    }
};
// @lc code=end

