/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0;
        int sums = 0;
        for (int i = 0; i < arr.size(); i++) {
            sums += arr[i];
            if (i>=k-1) {
                if (sums>=threshold*k) cnt++;
                sums -= arr[i-k+1];
            }
        }
        return cnt;
    }
};
// @lc code=end

