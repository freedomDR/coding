/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
        vector<TreeNode*> arr;
        arr.push_back(root);
        while(!arr.empty()) {
            int sums = 0;
            vector<TreeNode*> next_level_node;
            for(auto & node : arr) {
                if (node->left) {
                    sums += node->left->val;
                    next_level_node.push_back(node->left);
                }
                if (node->right) {
                    sums += node->right->val;
                    next_level_node.push_back(node->right);
                }
            }
            for (auto & node : arr) {
                int tmp = 0;
                if (node->left) tmp += node->left->val;
                if (node->right) tmp += node->right->val;
                if (node->left) node->left->val = sums-tmp;
                if (node->right) node->right->val = sums-tmp;
            }
            arr = next_level_node;
        }
        return root;
    }
};
// @lc code=end

