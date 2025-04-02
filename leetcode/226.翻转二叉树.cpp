/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        auto traverse = [](this auto self, TreeNode*root) 
        {
            if (!root)
                return;
            TreeNode *tmp = root->left;
            root->left = root->right;
            root->right = tmp;
            self(root->left);
            self(root->right);
        };
        traverse(root);
        return root;
    }
};
// @lc code=end

