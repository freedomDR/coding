/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    TreeNode* Convert(TreeNode* p)
    {
        if(p == NULL) return NULL;
        TreeNode *Head = NULL, *pre = NULL;
        stack<TreeNode*> s;
        while(p!=NULL||!s.empty()){
            while(p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if(Head == NULL){
                Head = p;
                pre = p;
            }else{
                pre->right = p;
                p->left = pre;
                pre = p;
            }
            p = p->right;
        }
        return Head;
    }
};
