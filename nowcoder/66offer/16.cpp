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
    ListNode* Merge(ListNode* p1, ListNode* p2)
    {
        if(p1 == NULL) return p2;
        if(p2 == NULL) return p1;
        ListNode* root;
        if(p1->val > p2->val) {
            root = p2;
            root->next = Merge(p1, p2->next);
        }else {
            root = p1;
            root->next = Merge(p1->next, p2);
        }
        return root;
    }
};
