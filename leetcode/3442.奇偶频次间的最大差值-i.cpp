/*
 * @lc app=leetcode.cn id=3442 lang=cpp
 *
 * [3442] 奇偶频次间的最大差值 I
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> cnt(26);
        for (char c:s) {
            cnt[c-'a']++;
        }
        int ans = -1000;
        for (int i = 0; i < 26; i++) {
            if (cnt[i]==0||cnt[i]%2==0) continue;
            for (int j = 0; j < 26; j++) {
                if (i==j||cnt[j]==0||cnt[j]%2==1) continue;
                int diff = cnt[i]-cnt[j];
                if (diff%2) ans = max(ans, diff);
            }
        }
        return ans;
    }
};
// @lc code=end

