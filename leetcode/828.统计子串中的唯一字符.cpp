/*
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int ans = 0;
        // slove 1
        // vector<int> prefix(n, -1), suffix(n, n);
        // vector<int> f(26, -1);
        // for (int i = 0; i < n; i++) {
        //     int p = s[i]-'A';
        //     prefix[i] = f[p];
        //     f[p] = i;
        // }
        // ranges::fill(f, n);
        // for (int i = n-1; i >= 0; i--) {
        //     int p = s[i]-'A';
        //     suffix[i] = f[p];
        //     f[p] = i;
        // }
        // for (int i = 0; i < n; i++) {
        //     ans += (i-prefix[i])*(suffix[i]-i);
        // }

        // slove 2
        vector<int> f1(26, -1), f2(26, -1);
        int cur = 0;
        for (int i = 0; i < n; i++) {
            int p = s[i]-'A';
            cur += i-f2[p] - (f2[p]-f1[p]);
            ans += cur;
            f1[p]=f2[p];
            f2[p]=i;
        }
        return ans;
    }
};
// @lc code=end

