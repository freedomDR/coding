/*
 * @lc app=leetcode.cn id=3532 lang=cpp
 *
 * [3532] 针对图的路径存在性查询 I
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<int> arr;
        for (int i = 0; i < n-1; i++) {
            if (nums[i+1]-nums[i] > maxDiff) {
                arr.push_back(i);
            }
        }
        for (auto & query : queries) {
            ans.push_back(lower_bound(arr.begin(), arr.end(), query[0])==lower_bound(arr.begin(), arr.end(), query[1]));
        }
        return ans;
    }
};
// @lc code=end

