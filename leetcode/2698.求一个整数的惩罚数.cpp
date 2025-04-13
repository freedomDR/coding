/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {

    bool check(int a, int b) {
        string bs = to_string(b);
        bool res = false;
        int len = bs.size();
        auto dfs = [&](this auto && self, int pos, int last_val, int sums) {
            if (res) return;
            if (sums > a) return;
            if (pos == len) {
                if (sums == a) {
                    res = true;
                }
                return;
            }
            // not split
            self(pos+1, last_val * 10 + (bs[pos] - '0'), sums - last_val + (last_val * 10 + (bs[pos] - '0')));
            // split
            self(pos+1, bs[pos] - '0', sums+(bs[pos] - '0'));
        };
        dfs(0, 0, 0);
        return res;
    }

public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i, i*i)) {
                //cout << i << " " << i*i << endl;
                ans += i*i;
            }
        }
        return ans;
    }
};
// @lc code=end

