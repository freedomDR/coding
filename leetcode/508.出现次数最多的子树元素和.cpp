/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> sumCount;
        vector<int> ans;
        auto dfs = [&](this auto && self, TreeNode * node) -> int {
            if (!node)
                return 0;
            int sums = node->val + self(node->left) + self(node->right);
            sumCount[sums]++;
            return sums;
        };
        dfs(root);
        int maxCount = 0;
        for (auto & [sum, count] : sumCount) {
            if (count > maxCount) {
                maxCount = count;
                ans.clear();
                ans.push_back(sum);
            } else if (count == maxCount) {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};
// @lc code=end

