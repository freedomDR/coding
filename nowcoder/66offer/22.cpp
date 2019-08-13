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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> visit;
        visit.push(root);
        while(!visit.empty()){
            TreeNode* node = visit.front();
            if(node->left != NULL) visit.push(node->left);
            if(node->right != NULL) visit.push(node->right);
            ans.push_back(node->val);
            visit.pop();
        }
        return ans;
    }
};
