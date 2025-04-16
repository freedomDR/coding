/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 统计各位数字都不同的数字个数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        if (n == 0) return 1;
        for (int i = n; i > 0; i--) {
            int cnt = 1;
            for (int j = 0; j < i; j++) {
                if (j == 0) {
                    cnt *= 9;
                } else {
                    cnt *= (10 - j);
                }
            }
            ans += cnt;
        }
        return ans+1;
    }
};
// @lc code=end

