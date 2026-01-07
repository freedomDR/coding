/*
 * @lc app=leetcode.cn id=2901 lang=cpp
 *
 * [2901] 最长相邻不相等子序列 II
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
#include <cinttypes>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<pii> dp(n);
        dp[0] = {1, 0};
        auto check = [&](int i, int j) -> bool {
            if (groups[i]==groups[j]) return false;
            if (words[i].size() != words[j].size()) return false;
            int diff = 0;
            for (int k = 0; k < words[i].size(); k++) {
                if (words[i][k]!=words[j][k]) diff++;
            }
            return diff==1;
        };
        for (int i = 1; i < n; i++) {
            dp[i] = {1, i};
            for (int j = 0; j < i; j++) {
                if (check(i, j) && dp[i].first < dp[j].first+1) {
                    dp[i] = {dp[j].first+1, j};
                }
            }
        }
        int max_v = 0;
        for (int i = 0; i < n; i++) max_v = max(max_v, dp[i].first);
        cout << max_v << endl;
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            if (max_v == dp[i].first) {
                int pos = i;
                ans.push_back(words[i]);
                while (dp[pos].second!=pos) {
                    pos = dp[pos].second;
                    ans.push_back(words[pos]);
                }
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// int main()
// {
//     vector<string> arr1 = {"bab","dab","cab"};
//     vector<int> arr2 = {1,2,2};
//     Solution s;
//     cout << s.getWordsInLongestSubsequence(arr1, arr2).size() << endl;
//     return 0;
// }
// @lc code=end

