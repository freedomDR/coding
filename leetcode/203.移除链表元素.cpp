/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy = ListNode(0, head);
        ListNode * pre = &dummy;
        while(head) {
            if (head->val == val) {
                pre->next = head->next;
                head = head->next;
            } else {
                pre = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end

