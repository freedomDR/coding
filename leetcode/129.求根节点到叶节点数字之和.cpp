/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto self, TreeNode * node, int sums) -> void 
        {
            if (!node) return;
            sums = sums * 10 + node->val;
            if (!node->left && !node->right) {
                ans += sums;
                return;
            }
            self(node->left, sums);
            self(node->right, sums);
        };
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end

