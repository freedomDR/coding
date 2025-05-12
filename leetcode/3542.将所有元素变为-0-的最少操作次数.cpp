/*
 * @lc app=leetcode.cn id=3542 lang=cpp
 *
 * [3542] 将所有元素变为 0 的最少操作次数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        deque<int> st;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty()&&nums[i]<st.back()) {
                st.pop_back();
                ans++;
            }
            if (st.empty()) st.push_back(nums[i]);
            else if (nums[i]>st.back()) st.push_back(nums[i]);
        }
        return ans+st.size()-(st.front()==0);
    }
};
// @lc code=end

