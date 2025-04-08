/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        auto dfs1 = [](this auto && self, TreeNode * node, long long left=LLONG_MIN, long long right=LLONG_MAX) -> bool {
            if (!node) return true;
            int x = node->val;
            return x>left && x<right && self(node->left, left, x) && self(node->right, x, right);
        };
        long long pre = LLONG_MIN;
        auto dfs2 = [&pre](this auto && self, TreeNode * node) -> bool {
            if (!node) return true;
            if (!self(node->left))
                return false;
            if (node->val <= pre)
                return false;
            pre = node->val;
            return self(node->right);
        };
        auto dfs3 = [](this auto && self, TreeNode * node) -> pair<long long, long long> {
            if (!node) return {LLONG_MAX, LLONG_MIN};
            auto [lmin, lmax] = self(node->left);
            auto [rmin, rmax] = self(node->right);
            if (lmax >= node->val || rmin <= node->val)
                return {LLONG_MIN, LLONG_MAX};
            return {min(lmin, node->val*1LL), max(rmax, node->val*1LL)};
        };  
        return dfs3(root).first != LLONG_MIN;
    }
};
// @lc code=end

