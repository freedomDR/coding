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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> ans;
            add(pRoot, 1, ans);
            return ans;
        }
    
        void add(TreeNode* p, int depth, vector<vector<int>>& ans){
            if(p == NULL) return;
            if(depth > ans.size()) ans.push_back(vector<int>());
            ans[depth-1].push_back(p->val);
            add(p->left, depth+1, ans);
            add(p->right, depth+1, ans);
        }
    
};
