/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
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
    int rangeSumBST(TreeNode* node, int low, int high) {
        if (!node) 
            return 0;
        if (node->val < low)
            return rangeSumBST(node->right, low, high);
        if (node->val > high)
            return rangeSumBST(node->left, low, high);
        return node->val + rangeSumBST(node->left, low, high) + rangeSumBST(node->right, low, high);
    }
};
// @lc code=end

