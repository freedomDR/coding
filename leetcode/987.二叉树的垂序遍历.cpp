/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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

struct NodeValue {
    int x;
    int y;
    int val;
    NodeValue(int x, int y, int val) : x(x), y(y), val(val) {}
    bool operator<(const NodeValue & other) const {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return val < other.val;
    }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<NodeValue>> m;
        auto dfs = [&](this auto self, TreeNode * node, int x, int y) -> void 
        {
            if (!node) return;
            if (!m.count(y)) m[y] = vector<NodeValue>();
            m[y].emplace_back(x, y, node->val);
            self(node->left, x+1, y-1);
            self(node->right, x+1, y+1);
        };
        dfs(root, 0, 0);
        for (auto& [_, v] : m) {
            sort(v.begin(), v.end());
            vector<int> temp;
            for (auto & value : v) {
                temp.push_back(value.val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

