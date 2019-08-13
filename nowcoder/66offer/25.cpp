/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        RandomListNode* node = pHead;
        while(node != NULL){
            RandomListNode* temp = new RandomListNode(node->label);
            temp->next = node->next;
            node->next = temp;
            node = temp->next;
        }
        node = pHead;
        while(node != NULL){
            if(node->random) node->next->random = node->random->next;
            node = node->next->next;
        }
        node = pHead;
        RandomListNode *ans = node->next, *pre=ans;
        while(node != NULL){
            node->next = node->next->next;
            if(node->next != NULL) pre->next = node->next->next;
            pre = pre->next;
            node = node->next;
        }
        return ans;
    }
};
