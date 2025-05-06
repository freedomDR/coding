/*
 * @lc app=leetcode.cn id=3537 lang=cpp
 *
 * [3537] 填充特殊网格
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> specialGrid(int n, int v = 0) {
        int N = pow(2, n);
        vector<vector<int>> res(N, vector<int>(N, 0));
        auto dfs = [&](this auto && dfs, int nn, int v, int i, int j) -> void {
            if (nn==0) {
                res[i][j] = v;
                return;
            }
            int NN = pow(2, nn);
            dfs(nn-1, v, i, j+NN/2);
            dfs(nn-1, v+NN*NN/4, i+NN/2, j+NN/2);
            dfs(nn-1, v+NN*NN/2, i+NN/2, j);
            dfs(nn-1, v+NN*NN*3/4, i, j);
        };
        dfs(n, 0, 0, 0);
        return res;
    }
};
// int main()
// {
//     Solution s;
//     auto arr = s.specialGrid(10);
//     for (auto & rows:arr) {
//         for (int v:rows)
//             cout << v << " ";
//         cout << endl;
//     }
//     return 0;
// }
// @lc code=end

