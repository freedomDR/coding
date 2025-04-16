/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

class Solution {

    int getMinErase(string & s) {
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
        min_erase += f;
        return min_erase;
    }

    pair<vector<int>, vector<int>> getSuffix(string & s) {
        int f = 0;
        vector<int> l_suffix(s.size()+1, 0);
        vector<int> r_suffix(s.size()+1, 0);
        for (int i = s.size()-1; i >= 0; i--) {
            l_suffix[i] = l_suffix[i+1] + (s[i] == '(' ? 1 : 0);
            r_suffix[i] = r_suffix[i+1] + (s[i] == ')' ? 1 : 0);
        }
        return {l_suffix, r_suffix};
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int f = 0;
        int min_erase = getMinErase(s);
        auto [l_suffix, r_suffix] = getSuffix(s);

        // cout << min_erase << endl;
        unordered_set<string> ans;
        vector<int> p;
        auto dfs1 = [&](this auto && self, int pos, int left, int right) {
            if (p.size()==min_erase) {
                if (left+l_suffix[pos] != right+r_suffix[pos]) return;
                while(pos < s.size()) {
                    if (left < right) return;
                    if (s[pos] == '(') left++;
                    if (s[pos] == ')') right++;
                    pos++;
                }
                if (left != right) return;
                string ss = s;
                for (int i = min_erase-1; i >= 0; i--)
                    ss.erase(p[i], 1);
                ans.insert(ss);
                return;
            }
            if (pos == s.size()) return;

            int new_left = left, new_right = right;
            if (s[pos] == '(') new_left++;
            if (s[pos] == ')') new_right++;
            if (new_left >= new_right) 
                self(pos+1, new_left, new_right);

            // rm
            if (s[pos] == '(' || s[pos] == ')') {
                p.push_back(pos);
                self(pos+1, left, right);
                p.pop_back();
            }

        };
        dfs1(0, 0, 0);
        return {ans.begin(), ans.end()};
    }
};

int main()
{
    Solution s;
    // (a)())()  )(
    auto res = s.removeInvalidParentheses("x(");
    cout << res.size() << endl;
    for (auto & s:res)
        cout << s << "***";
    cout << endl;
    res = s.removeInvalidParentheses("(a)())()");
    cout << res.size() << endl;
    for (auto & s:res)
        cout << s << "***";
    cout << endl;
    res = s.removeInvalidParentheses(")(");
    cout << res.size() << endl;
    for (auto & s:res)
        cout << s << "***";
    cout << endl;
    return 0;
}
// @lc code=end

