/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{};
        dummy.next = head;
        ListNode *cur = head, *l1 = head, *l2 = head, *pre = &dummy;
        while(n--)
            l2 = l2->next;
        while(l2)
        {
            pre = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        pre->next = pre->next->next;
        return dummy.next;
    }
};
// @lc code=end

