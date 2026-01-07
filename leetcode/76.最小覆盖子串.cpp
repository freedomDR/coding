/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int s_len = s.size(), t_len = t.size();
        unordered_map<char, int> t_cnt;
        for (auto c:t) t_cnt[c]++;
        string ans = "";
        unordered_map<char, int> cnt;
        int ok_c_num = 0;
        for (int i = 0; i < s_len; i++) {
            auto c = s[i];
            if (!t.contains(c)) continue;
            if (t_cnt.contains(c)) {
                cnt[c]++;
                if (cnt[c]==ok_c_num) ok_c_numfffffffffffffffffffff++;
            } 
            while () 
        }
    }
};
// @lc code=end

