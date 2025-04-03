/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }
        ListNode * dummy = new ListNode(0, head);
        ListNode * pre = dummy;
        ListNode * cur = pre->next;
        ListNode * l_p = dummy;
        while (len >= k) {
            for (int i = 0; i < k; i++, len--) {
                ListNode * next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            ListNode * tmp = l_p->next;
            l_p->next->next = cur;
            l_p->next = pre;
            l_p = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end

