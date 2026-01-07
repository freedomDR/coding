/*
 * @lc app=leetcode.cn id=2434 lang=cpp
 *
 * [2434] 使用机器人打印字典序最小的字符串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> suf(n+1);
        suf[n] = 'z';
        for (int i = n-1; i >= 0; i--) {
            suf[i] = min(suf[i+1], s[i]);
        }
        stack<char> st;
        string ans = "";
        for (int i = 0; i < n; i++) {
            st.push(s[i]);
            while (!st.empty() && st.top()<=suf[i+1]) {
                ans.push_back(st.top());
                st.pop();
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
// @lc code=end

