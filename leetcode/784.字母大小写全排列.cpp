/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {
    char change(char & c) {
        if ('a'<=c && c <='z')
            return 'A' + (c-'a');
        else if ('A'<=c && c <='Z')
            return 'a' + (c-'A');
        else
            return c;
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        auto dfs = [&](this auto && self, int pos) {
            if (pos >= s.size()) {
                ans.push_back(s);
                return;
            }
            self(pos+1);
            if (s[pos] >= 'A') {
                s[pos] = change(s[pos]);
                self(pos+1);
                // 不需要回溯了，因为只有当前字母只会反转一次
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

