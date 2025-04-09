/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        auto dfs = [&](this auto && self, TreeNode * node, bool is_left_children, TreeNode * parent) -> void {
            if (!node)
                return;
            if (to_delete_set.count(node->val)) {
                if (parent) {
                    if (is_left_children) {
                        parent->left = nullptr;
                    } else {
                        parent->right = nullptr;
                    }
                }
            }
            if (to_delete_set.count(node->val)) {
                if (node->left && !to_delete_set.count(node->left->val))
                    ans.push_back(node->left);
                if (node->right && !to_delete_set.count(node->right->val))
                    ans.push_back(node->right);
            }
            self(node->left, true, node);
            self(node->right, false, node);
        };
        dfs(root, true, nullptr);
        if (!to_delete_set.count(root->val)) 
            ans.push_back(root);
        return ans;
    }
};
// @lc code=end

