/*
 * @lc app=leetcode.cn id=3403 lang=cpp
 *
 * [3403] 从盒子中找出字典序最大的字符串 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string answerString(string word, int numFriends) {
        // if (numFriends==1) return word;
        // vector<vector<int>> cnt(26);
        // for (int i = 0; i < word.size(); i++) {
        //     cnt[word[i]-'a'].push_back(i);
        // }
        // int max_char_pos = -1;
        // for (int i = 25; i >= 0; i--) {
        //     if (cnt[i].size()>0) {
        //         max_char_pos = i;
        //         break;
        //     }
        // }
        // int substr_max_len = word.size()-(numFriends-1);
        // string ans = "";
        // for (int i = 0; i < cnt[max_char_pos].size(); i++) {
        //     int pos = cnt[max_char_pos][i];
        //     ans = max(ans, word.substr(pos, substr_max_len));
        // }
        // return ans;

        // if (numFriends == 1) return word;
        // string ans = "";
        // for (int i = 0; i < word.size(); i++) {
        //     ans = max(ans, word.substr(i, word.size()-(numFriends-1)));
        // }
        // return ans;
        if (numFriends == 1) return word;
        int i = 0, j = 1;
        while (j < word.size()) {
            int k = 0;
            while (j+k < word.size() && word[i+k] == word[j+k])
                k++;
            if (j+k < word.size() && word[i+k] < word[j+k]) {
                int tmp = i;
                i = j;
                j = max(j+1, tmp+k+1);
            } else {
                j += k+1;
            }
        }
        return word.substr(i, word.size()-numFriends+1);
    }
};
// @lc code=end

