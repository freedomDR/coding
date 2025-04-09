/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if (level % 2 == 0) {
                    if (node->val % 2 == 0 || (i != sz-1 && node->val >= q.front()->val)) {
                        //cout << "level: " << level << " i: " << i << " node->val: " << node->val << " q.front()->val: " << q.front()->val << endl;
                        return false;
                    }
                } else {
                    if (node->val % 2 != 0 || (i != sz-1 && node->val <= q.front()->val)) {
                        //cout << "level: " << level << " i: " << i << " node->val: " << node->val << " q.front()->val: " << q.front()->val << endl;
                        return false;
                    }
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};
// @lc code=end

