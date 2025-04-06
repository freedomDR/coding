/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * list2_last_node = list2;
        while(list2_last_node->next) {
            list2_last_node = list2_last_node->next;
        }
        ListNode * cur = list1;
        int pos = 0;
        while (++pos < a) {
            cur = cur->next;
        }
        ListNode * tmp = cur->next;
        cur->next = list2;
        cur = tmp;
        while (pos++ <= b) {
            cur = cur->next;
        }
        list2_last_node->next = cur;
        return list1;
    }
};
// @lc code=end

