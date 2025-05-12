#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

#include <vector>
#include <climits>  // For INT_MAX

class SegmentTree {
private:
    int n;  // 原始数组长度
    std::vector<int> tree;  // 线段树数组（大小为 4*n）

    // 递归建树
    void build(const std::vector<int>& data, int node, int start, int end) {
        if (start == end) {  // 叶子节点
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            int left_node = 2 * node + 1;  // 左子节点索引
            int right_node = 2 * node + 2; // 右子节点索引
            build(data, left_node, start, mid);    // 递归建左子树
            build(data, right_node, mid + 1, end); // 递归建右子树
            tree[node] = std::min(tree[left_node], tree[right_node]); // 合并结果
        }
    }

    // 单点更新
    void update(int node, int start, int end, int pos, int val) {
        if (start == end) {  // 找到目标叶子节点
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            if (pos <= mid) {  // 目标在左子树
                update(left_node, start, mid, pos, val);
            } else {           // 目标在右子树
                update(right_node, mid + 1, end, pos, val);
            }
            tree[node] = std::min(tree[left_node], tree[right_node]); // 更新父节点
        }
    }

    // 区间查询
    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {  // 区间无交集
            return INT_MAX;
        } else if (l <= start && end <= r) {  // 当前区间完全在查询范围内
            return tree[node];
        } else {  // 递归查询左右子树
            int mid = (start + end) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            int left_min = query(left_node, start, mid, l, r);
            int right_min = query(right_node, mid + 1, end, l, r);
            return std::min(left_min, right_min);
        }
    }

public:
    SegmentTree(const std::vector<int>& data) {
        n = data.size();
        tree.resize(4 * n, INT_MAX);  // 预留 4*n 空间
        build(data, 0, 0, n - 1);     // 从根节点（索引0）开始建树
    }

    // 单点更新接口（外部调用）
    void update(int pos, int val) {
        update(0, 0, n - 1, pos, val);
    }

    // 区间查询接口（外部调用）
    int queryMin(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 1 3 4 8 2 4 2 1
        // 0 3 4 8 2 4 2 0
        int ans = 0;
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        SegmentTree seg(nums);
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
        int max_v = *max_element(nums.begin(), nums.end());
        for (int i = 1; i <= max_v; i++) {
            if (!mp.contains(i)) continue;
            int tmp = 1;
            for (int j = 1; j < mp[i].size(); j++) {
                int l = mp[i][j-1], r = mp[i][j];
                int res = seg.queryMin(l, r);
                if (res != i) tmp++;
            }
            ans += tmp;
        }
        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> arr = {0, 2};
    cout << s.minOperations(arr) << endl;
    arr = {3,1,2,1};
    cout << s.minOperations(arr) << endl;
    arr = {1,2,1,2,1,2};
    cout << s.minOperations(arr) << endl;
    return 0;
}