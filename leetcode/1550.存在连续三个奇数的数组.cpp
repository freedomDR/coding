/*
 * @lc app=leetcode.cn id=1550 lang=cpp
 *
 * [1550] 存在连续三个奇数的数组
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (int v:arr) {
            if (v%2) cnt++;
            else cnt = 0;
            if (cnt == 3) return true;
        }
        return false;
    }
};
// @lc code=end

