/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans(n1, -1);
        unordered_map<int, int> pos;
        for (int i = 0; i < n1; i++) {
            pos[nums1[i]] = i;
        }

        stack<int> st;
        for (int i = 0; i < n2; i++) {
            while (!st.empty()&&nums2[i]>nums2[st.top()]) {
                auto p = st.top();
                st.pop();
                if (pos.count(nums2[p])) {
                    ans[pos[nums2[p]]] = nums2[i];
                }
            }
            st.push(i);
        }
        return ans;
    }
};
// @lc code=end

