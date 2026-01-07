/*
 * @lc app=leetcode.cn id=1931 lang=cpp
 *
 * [1931] 用三种不同颜色为网格涂色
 */

// @lc code=start
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
const ll MOD=1e9+7;


class Solution {
public:
    int colorTheGrid(int m, int n) {
        vector<int> pow3(m);
        pow3[0] = 1;
        for (int i = 1; i < m; i++) {
            pow3[i] = pow3[i-1]*3;
        }

        vector<int> valid;
        for (int i = 0; i < pow3[m-1]*3; i++) {
            bool ok = true;
            for (int j = 1; j < m; j++) {
                if (i/pow3[j]%3==i/pow3[j-1]%3) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                valid.push_back(i);
        }
        vector<vector<int>> g(valid.size());
        for (int i = 0; i < valid.size(); i++) {
            for (int j = 0; j < valid.size(); j++) {
                bool ok = true;
                for (int k = 0; k < m; k++) {
                    if (valid[i]/pow3[k]%3==valid[j]/pow3[k]%3) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    g[i].push_back(j);
                }
            }
        }

        vector cache(n, vector<int>(valid.size(), -1));
        auto dfs = [&](this auto && self, int i, int j) {
            if (i==0) {
                return 1;
            }
            int & res = cache[i][j];
            if (res != -1) return res;
            res = 0;
            for (int k:g[j]) {
                res = (res+self(i-1, k))%MOD;
            }
            return res;
        };
        int ans = 0;
        for (int i = 0; i < valid.size(); i++) {
            ans = (ans+dfs(n-1, i))%MOD;
        }
        return ans;
    }
};

// int main()
// {
//     Solution s;
//     cout << s.colorTheGrid(1, 1) << endl;
//     cout << s.colorTheGrid(1, 2) << endl;
//     cout << s.colorTheGrid(5, 5) << endl;
//     return 0;
// }
// @lc code=end

