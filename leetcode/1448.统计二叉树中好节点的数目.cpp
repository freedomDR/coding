/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto self, TreeNode * node, int max_val) -> void
        {
            if (!node) return;
            if (node->val >= max_val)
            {
                ans++;
                max_val = node->val;
            }
            self(node->left, max_val);
            self(node->right, max_val);
        };
        dfs(root, INT_MIN);
        return ans;
    }
};
// @lc code=end

