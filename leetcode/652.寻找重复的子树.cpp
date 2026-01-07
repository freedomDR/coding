/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string, int> cnt;
        auto dfs = [&](this auto && self, TreeNode * node) -> string {
            if (node == nullptr) return " ";
            string s = to_string(node->val)+"_"+self(node->left)+"_"+self(node->right);
            cnt[s]++;
            if (cnt[s] == 2)
                ans.push_back(node);
            return s;
        };
        dfs(root);
        return ans;
    }
};
// @lc code=end

