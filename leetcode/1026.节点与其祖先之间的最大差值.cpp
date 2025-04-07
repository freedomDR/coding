/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto && self, TreeNode * node, int min_v, int max_v) -> void {
            if (!node) {
                return;
            }
            min_v = min(min_v, node->val);
            max_v = max(max_v, node->val);
            ans = max(ans, max_v - min_v);
            self(node->left, min_v, max_v);
            self(node->right, min_v, max_v);
        };
        dfs(root, root->val, root->val);
        return ans;
    }
};
// @lc code=end

