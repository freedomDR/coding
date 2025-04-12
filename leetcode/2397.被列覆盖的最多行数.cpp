/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int ans = 0;
        set<int> zeroCols;
        int m = matrix.size(), n = matrix[0].size();

        auto getZeroRows = [&]() {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                bool has_one = false;
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 1 && zeroCols.count(j) == 0) {
                        has_one = true;
                        break;
                    }
                }
                if (!has_one) cnt++;
            }
            return cnt;
        };

        auto dfs = [&](this auto && self, int pos) {
            if (zeroCols.size() == numSelect) {
                ans = max(ans, getZeroRows());
                return;
            }
            for (int i = pos; n-i>=numSelect-zeroCols.size(); i++) {
                zeroCols.insert(i);
                self(i + 1);
                zeroCols.erase(i);
            }
        };

        dfs(0);
        return ans;

    }
};
// @lc code=end

