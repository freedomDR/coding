/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(-101, head);
        ListNode * pre = dummy;
        while(head) {
            ListNode * next = head->next;
            if (next && head->val == next->val) {
                while (next && head->val == next->val) {
                    next = next->next;
                }
                pre->next = next;
            } else {
                pre = head;
            }
            head = next;
        }
        return dummy->next;
    }
};
// @lc code=end

