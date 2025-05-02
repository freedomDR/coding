/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode * p = head;
        int len = 0;
        while (p) {
            len++;
            p = p->next;
        }
        vector<int> ans(len);
        stack<pair<int, int>> st;
        for (int i = 0; i < len; i++, head = head->next) {
            while (!st.empty()&&head->val>st.top().first) {
                auto [val, pos] = st.top();
                st.pop();
                ans[pos] = head->val;
            }
            st.emplace(head->val, i);
        }
        return ans;
    }
};
// @lc code=end

