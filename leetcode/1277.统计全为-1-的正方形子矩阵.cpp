/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

// @lc code=start
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (i && j && matrix[i][j]) 
                    matrix[i][j] += min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]});
                ans += matrix[i][j];
            }
        }
        return ans;
    }
};
// @lc code=end

