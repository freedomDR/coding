/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 *
 * [1696] 跳跃游戏 VI
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<pair<int, int>> max_d;
        int n = nums.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            while(!max_d.empty()&&i-max_d.front().first>k)
                max_d.pop_front();
            int nxt = nums[i];
            if (!max_d.empty()) {
                nxt = max_d.front().second + nums[i];
            }
            ans = max(ans, nxt);
            // cout << i << " " << nxt << endl;
            while(!max_d.empty()&&nxt>=max_d.back().second) {
                max_d.pop_back();
            }
            max_d.emplace_back(i, nxt);
        }
        return max_d.back().second;
    }
};

// int main()
// {
//     vector<int> arr = {1,-5,-20,4,-1,3,-6,-3};
//     Solution s;
//     cout << s.maxResult(arr, 2) << endl;
//     return 0;
// }
// @lc code=end

