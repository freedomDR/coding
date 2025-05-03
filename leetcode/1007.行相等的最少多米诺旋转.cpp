/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 *
 * [1007] 行相等的最少多米诺旋转
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        int n = tops.size();
        for (int i = 1; i <= 6; i++) {
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            for (int j = 0; j < n; j++) {
                if (tops[j]==i) cnt1++;
                if (bottoms[j]==i) cnt2++;
                if (tops[j]==i||bottoms[j]==i) cnt3++;
            }
            if (cnt3 == n) {
                ans = min({ans, n-cnt1, n-cnt2});
            }
        }
        return (ans==INT_MAX?-1:ans);
    }
};
// @lc code=end

