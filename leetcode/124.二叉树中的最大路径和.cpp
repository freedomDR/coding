/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        auto dfs = [&](this auto && self, TreeNode * node) -> int {
            if (!node) return 0;
            auto l = self(node->left);
            auto r = self(node->right);
            ans = max(ans, l+r+node->val);
            return max(0, max(l, r) + node->val);
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end

