/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int extra_add = 0) {
        if (!l1 && !l2)
        {
            return extra_add ? new ListNode(extra_add):nullptr;
        }
        if (!l1)
            swap(l1, l2);
        extra_add += l1->val + (l2?l2->val:0);
        l1->val = extra_add%10;
        l1->next = addTwoNumbers(l1->next, l2?l2->next:nullptr, extra_add/10);
        return l1;
    }
};
// @lc code=end

