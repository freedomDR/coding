/*
 * @lc app=leetcode.cn id=1163 lang=cpp
 *
 * [1163] 按字典序排在最后的子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1;
        int n = s.size();
        while (j < n) {
            int k = 0;
            while (j+k < n && s[i+k] == s[j+k])
                k++;
            if (j+k < n && s[i+k] < s[j+k]) {
                int tmp = i;
                i = j;
                j = max(j+1, tmp+k+1);
            } else {
                j += k+1;
            }
        }
        return s.substr(i);
    }
};
// @lc code=end

