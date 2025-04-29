/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    int rob(TreeNode* root) {
        auto dfs = [&](this auto && self, TreeNode * node) -> pair<int, int> {
            if (!node)
                return {0, 0};
            auto [l_rob, l_not_rob] = self(node->left);
            auto [r_rob, r_not_rob] = self(node->right);
            auto cur_rob = node->val + l_not_rob + r_not_rob;
            auto cur_not_rob = max(l_rob, l_not_rob) + max(r_rob, r_not_rob);
            return {cur_rob, cur_not_rob};
        };
        auto [cur_rob, cur_not_rob] = dfs(root);
        return max(cur_rob, cur_not_rob);
    }
};
// @lc code=end

