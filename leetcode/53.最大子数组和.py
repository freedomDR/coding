#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        ans = -1e6
        tmp_sum = 0
        for v in nums:
            tmp_sum += v
            ans = max(ans, tmp_sum)
            tmp_sum = max(tmp_sum, 0)
        return ans
        
# @lc code=end

