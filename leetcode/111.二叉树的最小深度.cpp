/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
#include <deque>
using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        // if (!root)
        //     return 0;
        // if (root->left && root->right)
        //     return 1 + min(minDepth(root->left), minDepth(root->right));
        // if (root->left)
        //     return 1 + minDepth(root->left);
        // return 1 + minDepth(root->right);

        if (!root)
            return 0;
        deque<TreeNode*> q;
        q.push_back(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop_front();
                if (!node->left && !node->right)
                    return level;
                if (node->left)
                    q.push_back(node->left);
                if (node->right)
                    q.push_back(node->right);
            }
        }
        return level;
    }
};
// @lc code=end

