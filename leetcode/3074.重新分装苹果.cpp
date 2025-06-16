/*
 * @lc app=leetcode.cn id=3074 lang=cpp
 *
 * [3074] 重新分装苹果
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size(), m = capacity.size();
        ranges::sort(capacity);
        int j = m-1;
        int sums = 0;
        for (int i = 0; i < n; i++) {
            sums -= apple[i];
            while (sums<0) {
                sums += capacity[j--];
            }
        }
        return (m-1)-(j+1)+1;
    }
};
// @lc code=end

