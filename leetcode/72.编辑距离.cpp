/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {       
        int n = word1.size(), m = word2.size();
        if (n==0 || m==0) return n + m;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
            for (int j = 1; j <= m; j++) {
                dp[0][j] = j;
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
                }
            }
        }
        return dp[n][m];
    }
};

// int main()
// {
//     Solution s;
//     string word1 = "sea", word2 = "ate";
//     cout << s.minDistance(word1, word2) << endl; // Output: 3
//     return 0;
// }
// @lc code=end

