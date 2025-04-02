/*
 * @lc app=leetcode.cn id=2643 lang=cpp
 *
 * [2643] 一最多的行
 */

// @lc code=start
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_one = 0, pos = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            int tmp_one = 0;
            for (auto & v:mat[i])
                if (v)
                    tmp_one++;
            if (tmp_one > max_one)
            {
                max_one = tmp_one;
                pos = i;
            }
        }
        return {pos, max_one};
    }
};
// @lc code=end

