/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 *
 * [1793] 好子数组的最大分数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int ans = 0;
        stack<int> st;
        st.push(-1);
        nums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            while (st.size()>1 && nums[i]<=nums[st.top()]) {
                auto p = st.top();
                st.pop();
                if (st.top()+1 <= k && i-1 >= k)
                    ans = max(ans, nums[p]*(i-st.top()-1));
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

