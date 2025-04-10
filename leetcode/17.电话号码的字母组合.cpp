/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <bits/stdc++.h>
#include <ranges>
using namespace std;

class Solution {
    vector<string> ss{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> ans;
        vector<char> p;
        auto dfs = [&](this auto && self, int i) {
            if (i == digits.size()) {
                string tmp = "";
                for (auto & c : p) tmp.push_back(c);
                ans.push_back(tmp);
                return;
            }
            for(auto & c : ss[digits[i]-'0']) {
                p.push_back(c);
                self(i+1);
                p.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

