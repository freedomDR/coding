/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        // int n = s.size();
        // vector<int> cache(n, -1);
        // vector<vector<int>> cache2(n, vector<int>(n, -1));
        // function<int(int, int)> isPa = [&](int l, int r) -> int {
        //     if (l>=r) return 1;
        //     auto & res = cache2[l][r];
        //     if (res != -1) return res;
        //     if (s[l]==s[r])
        //         res = isPa(l+1, r-1);
        //     else
        //         res = 0;
        //     return res;
        // };
        // function<int(int)> dfs = [&](int r) -> int {
        //     if (isPa(0, r)) return 0;
        //     auto & res = cache[r];
        //     if (res != -1) return res;
        //     res = INT_MAX;
        //     for (int l = 1; l <= r; l++) {
        //         if (isPa(l, r)==1) 
        //             res = min(res, dfs(l-1)+1);
        //     }
        //     return res;
        // };
        // return dfs(n-1);

        // dp[i][j] = dp[i-1][j-1] && s[i]==s[j]
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i+len-1<n; i++) {
                int l = i, r = i+len-1;
                dp[l][r] = dp[l+1][r-1]&&(s[l]==s[r]);
            }
        }

        vector<int> f(n+1, INT_MAX);
        f[0] = 0;
        for (int r = 1; r <= n; r++) {
            if (dp[0][r-1]) {
                f[r] = 0;
                continue;
            }
            for (int l = 1; l <= r; l++) {
                if (dp[l-1][r-1])
                    f[r] = min(f[r], f[l-1]+1);
            }
        }
        return f[n];    
    }
};

// int main()
// {
//     Solution s;
//     auto time_1 = std::chrono::high_resolution_clock::now();
//     cout << s.minCut("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << endl;
//     // cout << s.minCut("aab") << endl;
//     auto time_2 = std::chrono::high_resolution_clock::now();
//     std::chrono::duration<double, std::milli> cost = time_2-time_1;
//     std::cout << "cost " << cost.count() << "ms\n";
//     return 0;
// }
// @lc code=end

