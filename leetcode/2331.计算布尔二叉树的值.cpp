/*
 * @lc app=leetcode.cn id=2331 lang=cpp
 *
 * [2331] 计算布尔二叉树的值
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
    bool evaluateTree(TreeNode* root) {
        if (!root)
            return true;
        switch (root->val) {
            case 0:
                return false;
            case 1:
                return true;
            case 2:
                return evaluateTree(root->left) || evaluateTree(root->right);
            case 3:
                return evaluateTree(root->left) && evaluateTree(root->right);
            default:
                return false;
        }
    }
};
// @lc code=end

