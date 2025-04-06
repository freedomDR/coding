/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        auto findMidNode = [](ListNode * node) {
            ListNode * slow = node;
            ListNode * fast = node;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            };
            return slow;
        };
        auto reverseListNode = [](ListNode * node) {
            ListNode * pre = nullptr;
            while (node) {
                ListNode * next = node->next;
                node->next = pre;
                pre = node;
                node = next;
            }
            return pre;
        };
        ListNode * mid = findMidNode(head);
        ListNode * head2 = reverseListNode(mid);
        while (head2->next) {
            ListNode * next1 = head->next;
            ListNode * next2 = head2->next;
            head->next = head2;
            head2->next = next1;
            head = next1;
            head2 = next2;
        }
    }
};
// @lc code=end

