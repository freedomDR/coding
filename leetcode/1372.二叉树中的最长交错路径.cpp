/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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
#include <bits/iterator_concepts.h>
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto && self, TreeNode * node, int l, int r) -> void {
            ans = max(ans, max(l, r));
            if (node->left) {
                self(node->left, r + 1, 0);
            }
            if (node->right) {
                self(node->right, 0, l + 1);
            }
        };
        dfs(root, 0, 0);
        return ans;
    }
};
// @lc code=end

