/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto v:nums) s.insert(v);
        // unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto v:s) {
            if (s.contains(v-1)) continue;
            // x 是序列的起点
            int y = v + 1;
            while (s.contains(y)) { // 不断查找下一个数是否在哈希集合中
                y++;
            }
            // 循环结束后，y-1 是最后一个在哈希集合中的数
            ans = max(ans, y - v); // 从 x 到 y-1 一共 y-x 个数
        }
        return ans;

        // int ans = 0;
        // unordered_set<int> st(nums.begin(), nums.end()); // 把 nums 转成哈希集合
        // for (int x : st) { // 遍历哈希集合
        //     if (st.contains(x - 1)) {
        //         continue;
        //     }
        //     // x 是序列的起点
        //     int y = x + 1;
        //     while (st.contains(y)) { // 不断查找下一个数是否在哈希集合中
        //         y++;
        //     }
        //     // 循环结束后，y-1 是最后一个在哈希集合中的数
        //     ans = max(ans, y - x); // 从 x 到 y-1 一共 y-x 个数
        // }
        // return ans;
    }
};
// @lc code=end

