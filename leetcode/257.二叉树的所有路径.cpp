/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
using namespace std;

class Solution {
    string join(string && s, vector<TreeNode*> arr) {
        string res = "";
        for(auto & node : arr) {
            res += (res==""?"":s) + to_string(node->val);
        }
        return res;
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<TreeNode*> p;
        auto dfs = [&](this auto && self, TreeNode * node) -> void {
            if (!node->left&&!node->right) {
                ans.push_back(join("->", p));
            }
            if (node->left) {
                p.push_back(node->left);
                self(node->left);
                p.pop_back();
            }
            if (node->right) {
                p.push_back(node->right);
                self(node->right);
                p.pop_back();
            }
        };
        p.push_back(root);
        dfs(root);
        return ans;
    }
};
// @lc code=end

