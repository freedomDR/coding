/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL || pHead->next == NULL) return pHead;
        bool repeate = false;
        while(pHead->next != NULL && pHead->val == pHead->next->val) {pHead = pHead->next;repeate = true;}
        if(repeate) return deleteDuplication(pHead->next);
        pHead->next = deleteDuplication(pHead->next);
        return pHead;
    }
};
