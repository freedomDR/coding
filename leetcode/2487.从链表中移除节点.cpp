/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
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
#include <type_traits>
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode * node = removeNodes(head->next);
        if (node->val > head->val) {
            return node;
        }
        head->next = node;
        return head;
    }
};
// @lc code=end

