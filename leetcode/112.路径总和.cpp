/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        auto dfs = [&](this auto self, TreeNode* node, int sum) -> void {
            if (!node) return;
            if (ans) return;
            sum += node->val;
            if (!node->left && !node->right) {
                ans = sum == targetSum;
            } 
            self(node->left, sum);
            self(node->right, sum);
        };
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end

