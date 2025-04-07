/*
 * @lc app=leetcode.cn id=951 lang=cpp
 *
 * [951] 翻转等价二叉树
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        auto isSame = [](this auto && self, TreeNode * node1, TreeNode * node2) -> bool {
            if (!node1||!node2)
                return node1 == node2;
            if (node1->val != node2->val)
                return false;
            return (self(node1->left,node2->left)&&self(node1->right,node2->right))
                    || (self(node1->right,node2->left)&&self(node1->left,node2->right));
        };
        return isSame(root1, root2);
    }
};
// @lc code=end

