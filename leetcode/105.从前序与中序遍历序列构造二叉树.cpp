/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        int pos = ranges::find(inorder, preorder[0])-inorder.begin();
        vector<int> l_pre(preorder.begin()+1, preorder.begin()+1 + pos);
        vector<int> r_pre(preorder.begin()+1+pos, preorder.end());
        vector<int> l_in(inorder.begin(), inorder.begin()+pos);
        vector<int> r_in(inorder.begin()+pos+1, inorder.end());
        auto left = buildTree(l_pre, l_in);
        auto right = buildTree(r_pre, r_in);
        return new TreeNode(preorder[0], left, right);

    }
};
// @lc code=end

