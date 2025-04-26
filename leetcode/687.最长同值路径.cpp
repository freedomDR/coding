/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        auto dfs = [&](this auto && self, TreeNode * node) -> int {
            if (!node) return 0;
            auto left = self(node->left);
            auto right = self(node->right);
            if (node->left && node->left->val == node->val) {
                left++;
            } else {
                left = 0;
            }
            if (node->right && node->right->val == node->val) {
                right++;
            } else {
                right = 0;
            }
            ans = max(ans, left + right);
            return max(left, right);
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end

