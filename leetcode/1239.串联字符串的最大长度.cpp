/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */

// @lc code=start
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        erase_if(arr, [](string &s) {
            unordered_set<char> sset;
            for (auto &c : s) {
                if (sset.count(c)) return true;
                sset.insert(c);
            }
            return false;
        });

        sort(arr.begin(), arr.end(), [](string &a, string &b) {
            return a.size() > b.size();
        });
        
        vector<int> bits(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            bits[i] = 0;
            for (auto &c : arr[i]) {
                bits[i] |= (1 << (c - 'a'));
            }
        }

        vector<int> suffix_len(arr.size());
        for (int i = arr.size() - 1; i >= 0; i--) {
            suffix_len[i] = arr[i].size();
            if (i + 1 < arr.size()) {
                suffix_len[i] += suffix_len[i + 1];
            }
        }
        int v = 0;
        int tmp_len = 0;
        
        auto dfs = [&](this auto && self, int pos) {
            if (pos == arr.size()) {
                ans = max(ans, tmp_len);
                return;
            }
            for (int i = pos; i < arr.size(); i++) {
                if (tmp_len + suffix_len[pos] <= ans) return;
                if ((v&bits[i]) == 0) {
                    v |= bits[i];
                    tmp_len += arr[i].size();
                    self(i + 1);
                    tmp_len -= arr[i].size();
                    v &= ~bits[i];
                }
                self(i+1);
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

