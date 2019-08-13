/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* p) {
        if(p == NULL || p->next == NULL) return p;
        ListNode* head = ReverseList(p->next);
        p->next->next = p;
        p->next = NULL;
        return head;
    }
};
