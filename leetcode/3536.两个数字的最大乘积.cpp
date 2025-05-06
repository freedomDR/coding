/*
 * @lc app=leetcode.cn id=3536 lang=cpp
 *
 * [3536] 两个数字的最大乘积
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while(n) {
            arr.push_back(n%10);
            n /= 10;
        }
        ranges::sort(arr);
        int len = arr.size();
        return arr[len-1]*arr[len-2];
    }
};
// @lc code=end

