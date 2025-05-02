/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<int> st;
        // for (int i = 0; i < n; i++) {
        //     while (!st.empty()&&temperatures[i]>temperatures[st.top()]) {
        //         auto p = st.top();
        //         ans[p] = i-p;
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        for (int i = n-1; i >= 0; i--)  {
            while (!st.empty() && temperatures[i]>=temperatures[st.top()]) {
                st.pop();
            }
            if (!st.empty())
                ans[i] = st.top()-i;
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

