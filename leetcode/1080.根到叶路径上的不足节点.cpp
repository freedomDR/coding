/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] 根到叶路径上的不足节点
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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        auto dfs = [&](this auto && self, TreeNode * node, int sums) -> TreeNode* {
            if (!node) return nullptr;
            sums += node->val;
            if (!node->left && !node->right) {
                return sums < limit ? nullptr : node;
            }
            node->left = self(node->left, sums);
            node->right = self(node->right, sums);
            return (node->left || node->right) ? node : nullptr;
        };
        return dfs(root, 0);
    }
};
// @lc code=end

