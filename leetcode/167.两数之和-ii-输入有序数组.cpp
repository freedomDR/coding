/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l<r)
        {
            int x = numbers[l] + numbers[r];
            if (x == target)
                break;
            else if (x > target)
                r--;
            else
                l++;
        }
        return {l+1, r+1};
    }
};
// @lc code=end

