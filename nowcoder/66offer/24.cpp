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
    vector<vector<int>> ans;
    vector<int> temp;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL) return ans;
        temp.push_back(root->val);
        if(expectNumber == root->val && root->left == NULL &&root->right == NULL){
            ans.push_back(vector<int>(temp));
        }
        FindPath(root->left, expectNumber-root->val);
        FindPath(root->right, expectNumber-root->val);
        temp.pop_back();
        return ans;
    }
};
