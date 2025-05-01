/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int minCameraCover(TreeNode* root) {
        auto dfs = [&](this auto && dfs, TreeNode * node) -> tuple<int, int, int> {
            if (!node)
                return {INT_MAX/2, 0, 0};
            auto [l_me, l_fa, l_child] = dfs(node->left);
            auto [r_me, r_fa, r_child] = dfs(node->right);
            int me = min({l_me, l_fa, l_child}) + min({r_me, r_fa, r_child}) + 1;
            int fa = min(l_me, l_child) + min(r_me, r_child);
            int child = min({l_me+r_child, l_child+r_me, l_me+r_me});
            return {me, fa, child};
        };
        auto [me, fa, child] = dfs(root);
        return min(me, child);
    }
};
// @lc code=end

