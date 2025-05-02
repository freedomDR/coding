/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < 2*n; i++) {
            while(!st.empty()&&nums[i%n]>nums[st.top()%n]) {
                auto p = st.top();
                st.pop();
                if (p < n) {
                    ans[p] = nums[i%n];
                }
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

