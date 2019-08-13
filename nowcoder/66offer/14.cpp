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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *f1 = pListHead, *f2 = f1;
        while(k--){
            if(f2 == NULL) return NULL;
            f2 = f2->next;
        }
        while(f2 != NULL){
            f1 = f1->next;
            f2 = f2->next;
        }
        return f1;
    }
};
