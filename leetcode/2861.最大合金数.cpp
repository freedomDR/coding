/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 *
 * [2861] 最大合金数
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int l = 0, r = 1e9+1;
        while (l < r) {
            int mid = l + (r-l) / 2;
            long long min_cost = LLONG_MAX;
            for (int i = 0; i < k; i++) {
                long long need = 0;
                for (int j = 0; j < n; j++) {
                    if (1L * composition[i][j] * mid > stock[j]) {
                        need += (1L * composition[i][j] * mid - stock[j]) * cost[j];
                    }
                }
                min_cost = min(min_cost, need);
            }
            if (min_cost <= budget) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l-1;
    }
};
// @lc code=end

