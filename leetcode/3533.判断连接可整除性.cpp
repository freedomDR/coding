/*
 * @lc app=leetcode.cn id=3533 lang=cpp
 *
 * [3533] 判断连接可整除性
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(); // <= 13
        vector<int> len(n);
        for (int i = 0; i < n; i++) {
            len[i] = to_string(nums[i]).size();
        }
        vector<int> ans;
        vector<vector<int>> vis(1<<n, vector<int>(k));
        auto dfs = [&](this auto && dfs, int f, int v) -> bool {
            if (f == 0) return v == 0;
            if (vis[f][v]) return false;
            vis[f][v] = 1;
            //cout << f << " " << v << endl;
            for (int i = 0; i < n; i++) {
                if (f&(1<<i) && dfs(f^(1<<i), (v*(int)pow(10, len[i])+nums[i])%k) ) {
                    ans.push_back(nums[i]);
                    return true;
                }
            }
            return false;
        };
        if (!dfs((1<<n)-1, 0)) {
            return {};
        }
        ranges::reverse(ans);
        return ans;
    }
};

// int main()
// {
//     Solution s;
//     vector<int> arr = {3,12,45};
//     cout << s.concatenatedDivisibility(arr, 5).size() << endl;
//     return 0;
// }
// @lc code=end

