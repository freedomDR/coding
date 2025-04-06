/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
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
    int pairSum(ListNode* head) {
        auto findMidNode = [](ListNode * node) 
        {
            ListNode * slow = node;
            ListNode * fast = node;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        };
        auto reverseList = [](ListNode * node)
        {
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
        int maxSum = 0;
        while (head1 && head2) {
            maxSum = max(maxSum, head1->val + head2->val);
            head1 = head1->next;
            head2 = head2->next;
        }
        return maxSum;
    }
};
// @lc code=end

