/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // inorder l root r, postorder l r root
        if (postorder.empty())
            return nullptr;
        int pos = ranges::find(inorder, postorder.back())-inorder.begin();
        vector<int> l_in(inorder.begin(), inorder.begin()+pos);
        vector<int> l_post(postorder.begin(), postorder.begin()+pos);
        vector<int> r_in(inorder.begin()+1+pos, inorder.end());
        vector<int> r_post(postorder.begin()+pos, postorder.end()-1);
        auto left = buildTree(l_in, l_post);
        auto right = buildTree(r_in, r_post);
        return new TreeNode(postorder.back(), left, right);
    }
};
// @lc code=end

