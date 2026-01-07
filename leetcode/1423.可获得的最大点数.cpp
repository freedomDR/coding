/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int all_sums = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int n = cardPoints.size();
        k = n-k;
        if (k==0) return all_sums;
        int sums = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            sums += cardPoints[i];
            if (i>=k-1) {
                ans = min(ans, sums);
                sums -= cardPoints[i-k+1];
            }
        }
        return all_sums-ans;
    }
};
// @lc code=end

