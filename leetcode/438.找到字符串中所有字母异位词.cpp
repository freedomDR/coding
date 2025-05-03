/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // solution 1
        // vector<int> ans;
        // unordered_map<char, int> cnt;
        // for (auto c:p) cnt[c]++;
        // unordered_map<char, int> tmp;
        // int p_sz = p.size();
        // for (int i = 0; i < s.size(); i++) {
        //     tmp[s[i]]++;
        //     if (i>=p_sz)
        //         tmp[s[i-p_sz]]--;
        //     auto check = [&]() -> bool {
        //         for (auto [k, v]:cnt) {
        //             if (tmp[k] != v) return false;
        //         }
        //         return true;
        //     };
        //     if (check()) 
        //         ans.push_back(i-p_sz+1);
        // }
        // return ans;

        // solution 2
        vector<int> ans;
        unordered_map<char, int> cnt;
        for (auto c:p) cnt[c]++;
        int l = 0;
        int p_len = p.size();
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i]]--;
            while (cnt[s[i]] < 0) {
                cnt[s[l++]]++;
            }
            if (i-l+1==p_len)
                ans.push_back(l);
        }
        return ans;
    }
};
// @lc code=end

