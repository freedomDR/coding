/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
#include <deque>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1);
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i]+nums[i];
        }
        deque<int> d;
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while(!d.empty()&&prefix[i]<=prefix[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
            while(!d.empty()&&prefix[d.back()]-prefix[d.front()]>=k) {
                ans = min(ans, d.back()-d.front());
                d.pop_front();
            }
        }
        return (ans==INT_MAX?-1:ans);
    }
};
// @lc code=end

