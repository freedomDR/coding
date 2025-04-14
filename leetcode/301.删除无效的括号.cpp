/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int f = 0;
        int min_erase = 0;
        for (auto & c:s) {
            if (c == '(') f++;
            if (c == ')') f--;
            if (f < 0) {
                min_erase += abs(f);
                f = 0;
            }
        }
        cout << min_erase << endl;
        vector<string> ans;
        vector<int> p;
        auto dfs1 = [&](this auto && self, int pos, int left, int right) {
            if (p.size()==min_erase) {
                if (left == right) {
                    string ss = s;
                    for (int i = min_erase-1; i >= 0; i--) {
                        ss.erase(p[i]);
                    }
                    ans.push_back(ss);
                }
                return;
            }
            if (pos == s.size()) return;
            if (s[pos] != '(' && s[pos] != ')')
                self(pos+1, left, right);
            else {
                if (s[pos]=='(')
                    self(pos+1, left+1, right);
                else if (left < right+1)
                    self(pos+1, left, right+1);
            }
            // rm
            p.push_back(pos);
            self(pos+1, left, right);
            p.pop_back();

        };
        dfs1(0, 0, 0);
        return ans;
    }
};

int main()
{
    Solution s;
    // (a)())()  )(
    auto res = s.removeInvalidParentheses("()())()");
    cout << res.size() << endl;
    for (auto & s:res)
        cout << s << "***";
    cout << endl;
    return 0;
}
// @lc code=end

