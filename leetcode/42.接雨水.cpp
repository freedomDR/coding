/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // solution 1;
        // int n = height.size();
        // vector<int> prefix_max(n+1), suffix_max(n+1);
        // for (int i = 1; i <= n; i++) {
        //     prefix_max[i] = max(prefix_max[i-1], height[i-1]);
        // }
        // for (int i = n-2; i >= 0; i--) {
        //     suffix_max[i] = max(suffix_max[i+1], height[i+1]);
        // }
        // int ans = 0;
        // for (int i = 1; i < n-1; i++) {
        //     ans += max(0, min(prefix_max[i], suffix_max[i])-height[i]);
        // }
        // return ans;

        // solution 2
        // int n = height.size();
        // int l = 0, r = n-1, l_max = 0, r_max = 0;
        // int ans = 0;
        // while (l < r) {
        //     l_max = max(l_max, height[l]);
        //     r_max = max(r_max, height[r]);
        //     ans += (l_max<r_max?(l_max-height[l++]):(r_max-height[r--]));
        // }
        // return ans;
        
        //solution 3
        int n = height.size();
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty()&&height[i]>=height[st.top()]) {
                int p = st.top();
                st.pop();
                if (!st.empty())
                    ans += (min(height[i], height[st.top()])-height[p])*(i-st.top()-1);
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

