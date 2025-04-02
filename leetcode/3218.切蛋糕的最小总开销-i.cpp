/*
 * @lc app=leetcode.cn id=3218 lang=cpp
 *
 * [3218] 切蛋糕的最小总开销 I
 */

// @lc code=start
class Solution {
public:
    int minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        std::ranges::sort(h);
        std::ranges::sort(v);
        int i = 0, j = 0;
        long long ans = 0;
        while(i < m-1 || j < n-1)
        {
            if (i == m-1 || (j < n-1 && v[j] < h[i]))
                ans += v[j++] * (m-i);
            else  
                ans += h[i++] * (n-j);
        }
        return ans;
    }
};
// @lc code=end

