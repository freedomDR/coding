/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        unordered_map<char, int> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]]++;
            while (cnt[s[i]] > 1) {
                cnt[s[l++]]--;
            }
            ans = max(ans, i-l+1);
        }
        return ans;
    }
};
// @lc code=end

