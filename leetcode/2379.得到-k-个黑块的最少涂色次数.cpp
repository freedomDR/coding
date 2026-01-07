/*
 * @lc app=leetcode.cn id=2379 lang=cpp
 *
 * [2379] 得到 K 个黑块的最少涂色次数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int white_cnt = 0;
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i]=='W') white_cnt++;
            if (i>=k-1) {
                ans = min(ans, white_cnt);
                if (blocks[i-k+1]=='W') white_cnt--;
            }
        }
        return ans;
    }
};
// @lc code=end

