/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int t = 0;
        if(root == NULL ) return 0;
        if(root->val >= L && root->val <= R) t += root->val;
        return t+rangeSumBST(root->left, L, R)+rangeSumBST(root->right, L, R);
    }
};
