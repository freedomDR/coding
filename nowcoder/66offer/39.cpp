class Solution {
public:
    int len;
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return depth(pRoot) != -1;
    }
    
    int depth(TreeNode* p){
        if(p == NULL) return 0;
        int left = depth(p->left);
        if(left == -1) return -1;
        int right = depth(p->right);
        if(right == -1) return -1;
        return abs(left-right)>1?-1:1+max(left, right);
    }
};
