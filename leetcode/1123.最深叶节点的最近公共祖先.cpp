/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max_dep = 0;
        TreeNode * ans = nullptr;
        auto dfs1 = [&](this auto && self, TreeNode * node, int dep) {
            if (!node) {
                max_dep = max(max_dep, dep);
                return dep;
            }
            auto left_max_dep = self(node->left, dep+1);
            auto right_max_dep = self(node->right, dep+1);
            if (left_max_dep == right_max_dep && left_max_dep == max_dep)
                ans = node;
            return max(left_max_dep, right_max_dep);
        };
        // dfs1(root, 0);
        // return ans;
        auto dfs2 = [&](this auto && self, TreeNode * node) -> pair<int, TreeNode*> {
            if (!node) return {0, nullptr};
            auto [l_dep, l_lca] = self(node->left);
            auto [r_dep, r_lca] = self(node->right);
            if (l_dep > r_dep) return {l_dep+1, l_lca};
            if (l_dep < r_dep) return {r_dep+1, r_lca};
            return {l_dep+1, node};
        };
        return dfs2(root).second;
    }
};
// @lc code=end

