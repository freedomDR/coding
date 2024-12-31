#
# @lc app=leetcode.cn id=238 lang=python3
#
# [238] 除自身以外数组的乘积
#

# @lc code=start
class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = [1] * n
        tmp = 1
        for i, v in enumerate(nums):
            tmp *= v
            ans[i] = tmp
        tmp = 1
        for i in range(n-1, -1, -1):
            if (i == n-1):
                ans[i] = ans[i-1]
            elif (i == 0):
                tmp *= nums[i+1]
                ans[i] = tmp
            else:
                tmp *= nums[i+1]
                ans[i] = ans[i-1]*tmp
        return ans
        
# @lc code=end

