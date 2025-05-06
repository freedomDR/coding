/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;
        vector<vector<int>> cnt(10, vector<int>(10));
        for (int i = 0; i < dominoes.size(); i++) {
            int x = dominoes[i][0], y = dominoes[i][1];
            if (x==y)
                ans += cnt[x][y];
            else 
                ans += cnt[x][y]+cnt[y][x];
            cnt[x][y]++;
        }
        return ans;
    }
};
// @lc code=end

