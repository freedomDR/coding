/*
 * @lc app=leetcode.cn id=1475 lang=cpp
 *
 * [1475] 商品折扣后的最终价格
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty()&&prices[i]<=prices[st.top()]) {
                auto p = st.top();
                st.pop();
                ans[p] = prices[p]-prices[i];
            }
            st.push(i);
        }
        while(!st.empty()) {
            auto p = st.top();
            st.pop();
            ans[p] = prices[p];
        }
        return ans;
    }
};
// @lc code=end

