/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 *
 * [2816] 翻倍以链表形式表示的数字
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
    ListNode* doubleIt(ListNode* head) {
        auto reverse = [](ListNode * node) {
            ListNode * pre = nullptr;
            while(node) {
                ListNode * next = node->next;
                node->next = pre;
                pre = node;
                node = next;
            }
            return pre;
        };
        head = reverse(head);
        ListNode * dummy = new ListNode(0);
        ListNode * cur = dummy;
        int carry = 0;
        while(head || carry) {
            int sum = carry;
            if(head) {
                sum += head->val*2;
                head = head->next;
            }
            cur->next = new ListNode(sum % 10);
            carry = sum / 10;
            cur = cur->next;
        }
        return reverse(dummy->next);
    }
};
// @lc code=end

