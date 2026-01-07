/*
 * @lc app=leetcode.cn id=1456 lang=cpp
 *
 * [1456] 定长子串中元音的最大数目
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0;
        int cnt = 0;
        unordered_set<char> ss = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < s.size(); i++) {
            if (ss.count(s[i])) {
                cnt++;
            }
            if (i>=k-1) {
                ans = max(ans, cnt);
                if (ss.count(s[i-k+1])) cnt--;
            }
        }
        return ans;
    }
};
// @lc code=end

