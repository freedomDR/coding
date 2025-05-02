/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;
        heights.push_back(-1);
        st.push(-1);
        for (int i = 0; i < heights.size(); i++) {
            while (st.size() > 1 && heights[i]<=heights[st.top()]) {
                auto p = st.top();
                st.pop();
                ans = max(ans, heights[p]*(i-st.top()-1));
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

