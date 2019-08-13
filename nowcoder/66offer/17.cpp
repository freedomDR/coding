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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL||pRoot1 == NULL) return false;
        return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2)||HasSubtree(pRoot1->right, pRoot2);
    }
    
    bool isSubtree(TreeNode* t1, TreeNode* t2)
    {
        if(t2 == NULL) return true;
        if(t1 == NULL) return false;
        return t1->val == t2->val && isSubtree(t1->left, t2->left)&&isSubtree(t1->right, t2->right);
    }
    
};
