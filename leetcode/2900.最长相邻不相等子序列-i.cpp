/*
 * @lc app=leetcode.cn id=2900 lang=cpp
 *
 * [2900] 最长相邻不相等子序列 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        for (int i = 0; i < groups.size(); i++) {
            if (i==0||groups[i]!=groups[i-1]) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

