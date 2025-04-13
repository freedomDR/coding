/*
 * @lc app=leetcode.cn id=2212 lang=cpp
 *
 * [2212] 射箭比赛中的最大得分
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans;
        int used = 0;
        int score = 0;
        int ans_score = 0;
        vector<int> p(12, 0);
        auto dfs = [&](this auto && self, int pos) {
            if (pos == 12) {
                if (score > ans_score) {
                    ans_score = score;
                    ans = p;
                    if (used < numArrows) {
                        ans[0] += numArrows - used;
                    }
                }
                return;
            }
            // a+(a+1)+(a+2)+...+(a+k) = (k+1)*(2a+k)/2
            if (score+(11+pos)*(11-pos+1)/2 <= ans_score) {
                return;
            }
            for (int i = pos; i < 12; i++) {
                self(i+1);
                if (numArrows - used > aliceArrows[i]) {
                    used += aliceArrows[i] + 1;
                    score += i;
                    p[i] = aliceArrows[i] + 1;
                    self(i+1);
                    p[i] = 0;
                    used -= aliceArrows[i] + 1;
                    score -= i;
                } 
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

