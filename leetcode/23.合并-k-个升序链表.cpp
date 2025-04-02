/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include <queue>
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy{0};
        auto cmp = [](ListNode *p1, ListNode *p2)
        {
            return p1->val > p2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (auto &p : lists) 
        {
            if (p)
                pq.push(p);
            if (p && p->next)
                p = p->next;
        }
        ListNode *pre = &dummy;
        while(!pq.empty())
        {
            pre->next = pq.top();
            pq.pop();
            if (!pre->next->next)
                pq.push(pre->next->next);
            pre = pre->next;
        }
        return dummy.next;
    }
};
// @lc code=end

