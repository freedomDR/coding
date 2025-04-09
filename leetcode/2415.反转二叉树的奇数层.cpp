/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        vector<TreeNode*> arr;
        arr.push_back(root);
        int level = 0;
        while (!arr.empty()) {
            int sz = arr.size();
            if (level%2) {
                for (int i = 0; i < sz / 2; ++i) {
                    TreeNode* node1 = arr[i];
                    TreeNode* node2 = arr[sz - 1 - i];
                    swap(node1->val, node2->val);
                }
            } 
            vector<TreeNode*> q;
            for (int i = 0; i < sz; ++i) {
                TreeNode* node = arr[i];
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            swap(arr, q);
            ++level;
        }
        return root;
    }
};
// @lc code=end

