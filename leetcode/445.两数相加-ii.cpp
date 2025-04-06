/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto reverse = [](ListNode* head) {
            ListNode* prev = nullptr;
            while (head) {
                ListNode* next = head->next;
                head->next = prev;
                prev = head;
                head = next;
            }
            return prev;
        };
        l1 = reverse(l1);
        l2 = reverse(l2);
        auto add = [](ListNode* l1, ListNode* l2) {
            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;
            int carry = 0;
            while (l1 || l2 || carry) {
                int sum = carry;
                if (l1) {
                    sum += l1->val;
                    l1 = l1->next;
                }
                if (l2) {
                    sum += l2->val;
                    l2 = l2->next;
                }
                carry = sum / 10;
                curr->next = new ListNode(sum % 10);
                curr = curr->next;
            }
            return dummy->next;
        };
        ListNode* result = add(l1, l2);
        return reverse(result);
    }
};
// @lc code=end

