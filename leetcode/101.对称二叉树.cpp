/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool check(TreeNode* l, TreeNode* r) {
        if (!l || !r)
            return l == r;
        return l->val == r->val && check(l->left, r->right) && check(l->right, r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);   
    }
};
// @lc code=end

