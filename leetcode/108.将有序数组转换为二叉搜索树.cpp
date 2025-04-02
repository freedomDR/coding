/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
#include <new>
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       auto dfs = [&](this auto self, int l, int r) -> TreeNode*
       {
            if (l == r)
                return nullptr;
            int mid = l + (r-l)/2;
            return new TreeNode(nums[mid], self(l, mid), self(mid+1, r));
       }; 
       return dfs(0, nums.size());
    }
};
// @lc code=end

