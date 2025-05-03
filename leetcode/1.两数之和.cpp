/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //solution 1
        // unordered_map<int, int> cnt;
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     int b = target-nums[i];
        //     if (cnt.count(b))
        //         return {cnt[b], i};
        //     cnt[nums[i]] = i;
        // }
        // return {-1, -1};

        // solution 2
        int n = nums.size();
        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[i] = i;
        ranges::sort(pos, [&](int i, int j){ return nums[i] < nums[j];});
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int tmp = nums[pos[l]]+nums[pos[r]];
            if (tmp==target) 
                return {pos[l], pos[r]};
            else if (tmp < target) {
                l++;
            } else {
                r--;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end

