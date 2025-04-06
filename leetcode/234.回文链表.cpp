/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        auto findMidNode = [](ListNode * node) {
            ListNode * slow = node;
            ListNode * fast = node;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        };
        auto reverseList = [](ListNode * node) {
            ListNode * pre = nullptr;
            while (node) {
                ListNode * next = node->next;
                node->next = pre;
                pre = node;
                node = next;
            }
            return pre;
        };
        ListNode * head1 = head;
        ListNode * head2 = reverseList(findMidNode(head));
        while (head1 && head2) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};
// @lc code=end

