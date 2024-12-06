#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#

# @lc code=start
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        not_zero_pos = 0
        for pos in range(len(nums)):
            if (nums[pos]):
                nums[pos], nums[not_zero_pos] = nums[not_zero_pos], nums[pos]
                not_zero_pos += 1
        return nums
        
# @lc code=end

