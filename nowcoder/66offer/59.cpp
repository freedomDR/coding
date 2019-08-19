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
        if(pRoot == NULL) return ans;
        stack<TreeNode*> s1, s2;
        int cur = 1;
        s1.push(pRoot);
        while(!s1.empty() || !s2.empty()){
            if(cur == 1){
                vector<int> temp;
                while(!s1.empty()){
                    TreeNode* node = s1.top();s1.pop();
                    temp.push_back(node->val);
                    if(node->left != NULL) s2.push(node->left);
                    if(node->right != NULL) s2.push(node->right);
                }
                if(!temp.empty()) ans.push_back(temp);
                cur = 2;
            }else{
                vector<int> temp;
                while(!s2.empty()){
                    TreeNode* node = s2.top();s2.pop();
                    temp.push_back(node->val);
                    if(node->right != NULL) s1.push(node->right);
                    if(node->left != NULL) s1.push(node->left);
                }
                if(!temp.empty()) ans.push_back(temp);
                cur = 1;
            }
        }
        return ans;
    }
    
};
