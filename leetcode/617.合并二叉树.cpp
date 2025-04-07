/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        auto merge = [](this auto && self, TreeNode * node1, TreeNode * node2) -> TreeNode* {
            if (node1==nullptr&&node2==nullptr)
                return nullptr;
            if (node1==nullptr)
                return node2;
            if (node2==nullptr)
                return node1;
            TreeNode * left = self(node1->left, node2->left);
            TreeNode * right = self(node1->right, node2->right);
            node1->val += node2->val;
            node1->left = left;
            node1->right = right;
            return node1;
        };
        return merge(root1, root2);
    }
};
// @lc code=end

