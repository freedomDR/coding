/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] 使数组严格递增
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // int n = arr1.size();
        // ranges::sort(arr2);
        // vector<unordered_map<int, int>> cache(n);
        // auto dfs = [&](this auto && self, int pos, int pre) -> int {
        //     if (pos < 0) return 0;
        //     if (auto it = cache[pos].find(pre); it != cache[pos].end())
        //         return it->second;
        //     // not choice
        //     int res = arr1[pos] < pre ? self(pos-1, arr1[pos]):INT_MAX/2;
        //     // choice
        //     auto it = lower_bound(arr2.begin(), arr2.end(), pre);
        //     if (it != arr2.begin()) {
        //         res = min(res, self(pos-1, *(it-1))+1);
        //     }
        //     return cache[pos][pre] = res;
        // };
        // int ans = dfs(n-1, INT_MAX);
        // return ans < INT_MAX/2 ? ans:-1;

        ranges::sort(arr2);
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        const int maxv = 1e9+10;
        arr1.push_back(maxv);
        arr1.insert(arr1.begin(), -1);
        int n = arr1.size();
        vector<int> dp(n, maxv);
        //dp[i] arr1 以下标i结束的最小替换数量（使满足严格递增，不替换arr1[i]）
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int j = lower_bound(arr2.begin(), arr2.end(), arr1[i])-arr2.begin();
            // arr2[x] < arr1[i] 的数有j个 arr1 最多替换i-1个
            for (int k = 1; k <= min(i-1, j); k++) {
                if (arr1[i-k-1] < arr2[j-k]) 
                    dp[i] = min(dp[i], dp[i-k-1]+k);
            }
            if (arr1[i-1] < arr1[i])
                dp[i] = min(dp[i], dp[i-1]);
        }
        return dp[n-1]>=maxv?-1:dp[n-1];
    }
};
// @lc code=end

