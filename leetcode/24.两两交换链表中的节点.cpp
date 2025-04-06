/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummy = new ListNode(0, head);
        ListNode * pre = dummy;
        ListNode * cur = head;
        ListNode * left = dummy;
        while (cur && cur->next) {
            // reverse one
            ListNode * next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            // reverse two
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            // connect
            ListNode * tmp = left->next;
            left->next->next = cur;
            left->next = pre;
            left = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end

