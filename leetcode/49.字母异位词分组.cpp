/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            string ss = strs[i];
            sort(ss.begin(), ss.end());
            mp[ss].push_back(strs[i]);
        }
        for (auto & [k, arr]:mp) {
            ans.push_back(arr);
        }
        return ans;
    }
};
// @lc code=end

