/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
#include <list>
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;
        for (int i = 1; i < left; ++i) {
            pre = pre->next;
        }
        auto l_pos = pre;
        auto cur = pre->next;
        for (int i = left; i <= right; ++i) {
            auto next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        l_pos->next->next = cur;
        l_pos->next = pre;
        return dummy->next;
    }
};
// @lc code=end

