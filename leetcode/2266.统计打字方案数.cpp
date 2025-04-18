/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 *
 * [2266] 统计打字方案数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD = 1e9+7;
        vector<int> f(pressedKeys.size()+1, 0);
        f[0] = 1;
        for (int i = 1; i <= pressedKeys.size(); i++) {
            auto c = pressedKeys[i-1];
            int len = (c=='7'||c=='9')?4:3;
            for (int j = 1; j <= len; j++) {
                f[i] = (f[i]+f[i-j])%MOD;
                if (i-j == 0) break;
                if (pressedKeys[i-j-1] != c) break;
            }
        }
        return f[pressedKeys.size()];
    }
};

// int main()
// {
//     Solution s;
//     cout << s.countTexts("2222") << endl;
//     return 0;
// }
// @lc code=end

