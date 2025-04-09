/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
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
#include <cstddef>
#include <memory>
using namespace std;

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path = "";
        vector<char> tmp_path;
        auto dfs = [&](this auto && self, TreeNode * node, int target) -> void {
            if (!node) return;
            if (node->val == target) {
                path = "";
                for (auto & v : tmp_path)
                    path.push_back(v);
                return;
            }
            tmp_path.push_back('L');
            self(node->left, target);
            tmp_path.pop_back();
            tmp_path.push_back('R');
            self(node->right, target);
            tmp_path.pop_back();
        };
        dfs(root, startValue);
        string start_path = path;
        tmp_path.clear();
        dfs(root, destValue);
        string dest_path = path;
        if (start_path.empty()) return dest_path;
        if (dest_path.empty()) return string(start_path.size(), 'U');
        // cout << start_path << " " << dest_path << endl;
        int pos = 0;
        while(start_path[pos]==dest_path[pos]) pos++;
        // cout << pos << endl;
        return string(start_path.substr(pos).size(), 'U') + dest_path.substr(pos);
    }
};
// @lc code=end

