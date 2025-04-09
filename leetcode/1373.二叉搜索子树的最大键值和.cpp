/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto && self, TreeNode* node) -> tuple<int, int, int> {
            if (!node) return {0, INT_MAX, INT_MIN};
            auto [l_sum, l_min, l_max] = self(node->left);
            auto [r_sum, r_min, r_max] = self(node->right);
            if (l_max < node->val && node->val < r_min) {
                int sum = l_sum + r_sum + node->val;
                ans = max(ans, sum);
                return {sum, min(l_min, node->val), max(r_max, node->val)};
            }
            return {0, INT_MIN, INT_MAX};
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end

