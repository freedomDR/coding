/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */

// @lc code=start
#include <bits/ranges_algo.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        ranges::sort(price);
        int l = 0, r = price.back() - price.front() + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int cnt = 1, last = price[0];
            for (int i = 1; i < price.size(); ++i) {
                if (price[i] - last >= m) {
                    ++cnt;
                    last = price[i];
                    if (cnt >= k) {
                        break;
                    }
                }
            }
            if (cnt >= k) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l - 1;
    }
};
// @lc code=end

