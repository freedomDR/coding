/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto self, TreeNode* node) -> int
        {
            if (!node)
                return 0;
            auto l = self(node->left);
            auto r = self(node->right);
            ans = max(ans, l+r);
            return max(l, r) + 1;
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end

