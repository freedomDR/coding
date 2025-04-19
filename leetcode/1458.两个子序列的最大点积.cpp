/*
 * @lc app=leetcode.cn id=1458 lang=cpp
 *
 * [1458] 两个子序列的最大点积
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        // dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + nums1[i-1] * nums2[j-1], nums1[i-1] * nums2[j-1])
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m+1, -1e9);
        // dp[1][1..n]
        for (int i = 1; i <= m; i++) dp[i] = max(dp[i-1], nums1[0] * nums2[i-1]);
        // dp[2..n][1..m]
        for (int i = 2; i <= n; ++i) {
            int pre = 0;
            for (int j = 1; j <= m; ++j) {
                int temp = dp[j];
                dp[j] = max({dp[j], dp[j-1], pre + nums1[i-1] * nums2[j-1], nums1[i-1] * nums2[j-1]});
                pre = temp;
            }
        }
        return dp[m];
    }
};

// int main()
// {
//     Solution s;
//     vector<int> arr1 = {-3,-8,3,-10,1,3,9}, arr2 = {9,2,3,7,-9,1,-8,5,-1,-1};
//     cout << s.maxDotProduct(arr1, arr2) << endl;
//     return 0;
// }
// @lc code=end

