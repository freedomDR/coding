/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (!root) return ans;
        vector<int> p;
        auto dfs = [&](this auto && self, TreeNode * node, int sums) -> void {
            if (!node->left && !node->right) {
                if (sums == targetSum) ans.push_back(p);
                return;
            }
            if (node->left) {
                p.push_back(node->left->val);
                self(node->left, sums+node->left->val);
                p.pop_back();
            }
            if (node->right) {
                p.push_back(node->right->val);
                self(node->right, sums+node->right->val);
                p.pop_back();
            }
        };
        p.push_back(root->val);
        dfs(root, root->val);
        return ans;
    }
};
// @lc code=end

