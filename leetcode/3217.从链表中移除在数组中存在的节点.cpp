/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 *
 * [3217] 从链表中移除在数组中存在的节点
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy(-1, head);
        ListNode * pre = &dummy;
        set<int> s;
        for (auto v : nums) 
            s.insert(v);
        while (head) {
            if (s.count(head->val)) {
                pre->next = head->next;
                head = pre->next;
            } else {
                pre = head;
                head = head->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end

