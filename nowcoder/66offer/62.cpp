/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL) return NULL;
        stack<TreeNode*> st;
        int len = 0;
        while(!st.empty() || pRoot != NULL){
            if(pRoot != NULL){
                st.push(pRoot);
                pRoot = pRoot->left;
            }else{
                pRoot = st.top();
                st.pop();
                len++;
                if(k == len) return pRoot;
                pRoot = pRoot->right;
            }
        }
        return NULL;
    }
    
};
