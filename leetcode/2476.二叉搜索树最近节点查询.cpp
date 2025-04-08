/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> arr;
        auto dfs = [&arr](this auto && self, TreeNode * node) {
            if (!node)
                return;
            self(node->left);
            arr.push_back(node->val);
            self(node->right);
        };
        dfs(root);
        // for (auto & v : arr)
        //     cout << v << " ";
        // cout << endl;
        vector<vector<int>> ans;
        auto low_bound = [](vector<int> & arr, int target) -> int {
            int l = 0, r = arr.size();
            while (l < r) {
                int mid = l + (r-l)/2;
                if (arr[mid] < target) {
                    l = mid+1;
                } else {
                    r = mid;
                }
            }
            return l;
        };
        for (auto & query : queries) {
            int pos = low_bound(arr, query);
            if (pos == arr.size()) {
                ans.push_back({arr[pos-1], -1});
            } else if (arr[pos] == query) {
                ans.push_back({query, query});
            } else {
                if (pos == 0) 
                    ans.push_back({-1, arr[pos]});
                else
                    ans.push_back({arr[pos-1], arr[pos]});
            }
        }
        return ans;
    }
};
// @lc code=end

