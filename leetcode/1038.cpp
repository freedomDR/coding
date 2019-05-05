#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int v = 0;
        travel(root, v);
        return root;
    }
    
    void travel(TreeNode* root, int& val) {
        if(root == NULL) return;
        travel(root->right, val);
        val += root->val;
        root->val = val;
        travel(root->left, val);
    }
};
int main()
{
    return 0;
}
