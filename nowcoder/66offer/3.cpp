/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        get(ans, head);
        return ans;
    }
    
    void get(vector<int>& ans, ListNode* head) {
        if(head == NULL) return;
        get(ans, head->next);
        ans.push_back(head->val);
    }
};
