/*
 * @lc app=leetcode.cn id=3219 lang=cpp
 *
 * [3219] 切蛋糕的最小总开销 II
 */

// @lc code=start
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        ranges::sort(h);
        ranges::sort(v);
        int i = 0, j = 0;
        long long ans = 0;
        while (i < m-1 || j < n-1)
        {
            if (j == n-1 || i < m-1 && h[i] < v[j])
                ans += h[i++] * (n-j);
            else
                ans += v[j++] * (m-i);
        }
        return ans;
    }
};
// @lc code=end

