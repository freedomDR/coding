/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        // for (int i = n-1; i >= 0; i--) {
        //     while (!st.empty() && heights[i]>st.top()) {
        //         st.pop();
        //         ans[i]++;
        //     }
        //     if (!st.empty()) ans[i]++;
        //     st.push(heights[i]);
        // }
        for (int i = 0; i < n; i++) {
            while (!st.empty()&&heights[i]>heights[st.top()]) {
                ans[st.top()]++;
                st.pop();
            }
            if (!st.empty())
                ans[st.top()]++;
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

