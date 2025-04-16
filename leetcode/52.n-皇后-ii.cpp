/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> columns;
        vector<bool> column_used(n, false);
        vector<bool> left_diagonal_used(2 * n - 1, false);
        vector<bool> right_diagonal_used(2 * n - 1, false);
        auto dfs = [&](this auto && self, int rows) {
            if (rows == n) {
                vector<string> tmp;
                for (int i = 0; i < n; i++) {
                    string s = string(n, '.');
                    s[columns[i]] = 'Q';
                    tmp.push_back(s);
                }
                ans.push_back(tmp);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (column_used[i]) continue;
                if (left_diagonal_used[rows + i]) continue;
                if (right_diagonal_used[rows - i + n - 1]) continue;
                columns.push_back(i);
                column_used[i] = true;
                left_diagonal_used[rows + i] = true;
                right_diagonal_used[rows - i + n - 1] = true;
                self(rows + 1);
                columns.pop_back();
                column_used[i] = false;
                left_diagonal_used[rows + i] = false;
                right_diagonal_used[rows - i + n - 1] = false;
            }
        };
        dfs(0);
        return ans.size();
    }
};
// @lc code=end

