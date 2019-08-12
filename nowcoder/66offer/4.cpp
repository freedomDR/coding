/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        return product(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
    }
    
    TreeNode* product(vector<int>& pre, vector<int>& vin, int pl, int pr, int vl, int vr) {
        if(vl > vr || pl > pr) return NULL;
        TreeNode* root = new TreeNode(pre[pl]);
        int midv = 0;
        for(int i = vl; i <= vr; i++) {
            if(vin[i] == pre[pl]) {midv = i; break;} 
        }
        root->left = product(pre, vin, pl+1, pl+(midv-vl), vl, midv-1);
        root->right = product(pre, vin, pl+(midv-vl)+1, pr, midv+1, vr);
        return root;
    }
};
