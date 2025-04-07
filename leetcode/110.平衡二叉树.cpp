/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        auto dfs = [&](this auto self, TreeNode * node)
        {
            if (!node) return 0;
            int left = self(node->left);
            if (left == -1) return -1;
            int right = self(node->right);
            if (right == -1) return -1;
            if (abs(left - right) > 1)
                return -1;
            return max(left, right) + 1;
        };
        return dfs(root) != -1;
    }
};
// @lc code=end

