/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> findMode(TreeNode* root) {
        int cnt = 1;
        int pre = -1e6;
        int max_cnt = 0;
        vector<int> ans;
        auto dfs = [&](this auto && self, TreeNode * node) -> void {
            if (!node) return;
            self(node->left);
            if (node->val == pre) {
                cnt++;
            } else {
                if (cnt > max_cnt && pre != -1e6) {
                    max_cnt = cnt;
                    ans.clear();
                    ans.push_back(pre);
                } else if (cnt == max_cnt) {
                    ans.push_back(pre);
                }
                cnt = 1;
                pre = node->val;
            }
            pre = node->val;
            self(node->right);
        };
        dfs(root);
        if (cnt > max_cnt) {
            ans.clear();
            ans.push_back(pre);
        } else if (cnt == max_cnt) {
            ans.push_back(pre);
        }

        return ans;
    }
};
// @lc code=end

