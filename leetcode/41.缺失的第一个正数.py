#
# @lc app=leetcode.cn id=41 lang=python3
#
# [41] 缺失的第一个正数
#

# @lc code=start
class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        for i in range(len(nums)):
            while nums[i] > 0 and nums[i] <= len(nums) and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1
        
# @lc code=end

