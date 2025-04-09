/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.empty())
            return nullptr;
        if (preorder.size()==1)
            return new TreeNode(preorder[0]);
        // preorder root l r, postorder l r root
        auto l_pos_postorder = ranges::find(postorder, preorder[1])-postorder.begin();
        vector<int> l_pre(preorder.begin()+1, preorder.begin()+1+l_pos_postorder+1);
        vector<int> l_post(postorder.begin(), postorder.begin()+l_pos_postorder+1);
        vector<int> r_pre(preorder.begin()+1+l_pos_postorder+1, preorder.end());
        vector<int> r_post(postorder.begin()+l_pos_postorder+1, postorder.end()-1);
        auto left = constructFromPrePost(l_pre, l_post);
        auto right = constructFromPrePost(r_pre, r_post);
        return new TreeNode(preorder[0], left, right);
    }
};
// @lc code=end

