/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution {

    template<typename  T>
    bool forwardCheck(T && s) {
        return check(std::forward<T>(s));
    }

    bool check(string && s) {
        for (int i = 0, ii = s.size()-1; i < ii; i++, ii--) {
            if (s[i] != s[ii])
                return false;
        }
        return true;
    }

    bool check(string & s) {
        for (int i = 0, ii = s.size()-1; i < ii; i++, ii--) {
            if (s[i] != s[ii])
                return false;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> p;
        auto dfs1 = [&](this auto && self, int pos, int pre) {
            if (pos == s.size()) {
                if (pre == pos) {
                    ans.push_back(p);
                }
                return;
            }
            self(pos+1, pre);
            if (forwardCheck(s.substr(pre, pos-pre+1))) {
                p.push_back(s.substr(pre, pos-pre+1));
                self(pos+1, pos+1);
                p.pop_back();

            }
        };
        // dfs1(0, 0);
        auto dfs2 = [&](this auto && self, int pos) {
            if (pos == s.size()) {
                ans.push_back(p);
                return;
            }
            for (int i = pos; i < s.size(); i++) {
                string tmp = s.substr(pos, i-pos+1);
                if (forwardCheck(tmp)) {
                    p.push_back(tmp);
                    self(i+1);
                    p.pop_back();
                }
            }
        };
        dfs2(0);
        return ans;

    }
};
// @lc code=end

