/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
#include <climits>

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        auto dfs1 = [&ans](this auto && self, TreeNode * node, int l = -1e6, int r = 1e6) -> void {
            if (!node)  
                return;
            ans = min(ans, min(abs(node->val-l), abs(r-node->val)));
            self(node->left, l, node->val);
            self(node->right, node->val, r);
        };
        // dfs1(root);
        int pre = -1e8;
        auto dfs2 = [&pre, &ans](this auto && self, TreeNode * node) -> void {
            if (!node)
                return;
            self(node->left);
            ans = min(ans, node->val-pre);
            pre = node->val;
            self(node->right);
        };
        // dfs2(root);
        auto dfs3 = [&ans](this auto && self, TreeNode * node) -> pair<int, int> {
            if (!node)
                return {1e6, -1e6};
            auto [l_min, l_max] = self(node->left);
            auto [r_min, r_max] = self(node->right);
            ans = min(ans, min(abs(node->val-l_max), abs(r_min-node->val)));
            return {min(l_min, node->val), max(r_max, node->val)};
        };
        dfs3(root);
        return ans;
    }
};
// @lc code=end

