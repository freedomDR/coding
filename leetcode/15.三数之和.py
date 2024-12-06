#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#

# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        ans = []
        for pos, x in enumerate(nums):
            if (pos+2 == len(nums)):
                break
            if (pos > 0 and nums[pos-1] == nums[pos]): continue
            if (x+nums[pos+1]+nums[pos+2] > 0): break
            if (x+nums[-1]+nums[-2] < 0): continue
            l, r = pos+1, len(nums)-1
            while (l < r):
                s = x + nums[l] + nums[r]
                if (s == 0):
                    ans.append([nums[pos], nums[l], nums[r]])
                    l += 1
                    while (l < r and nums[l] == nums[l-1]):
                        l += 1
                    r -= 1
                    while (l < r and nums[r] == nums[r+1]):
                        r -= 1
                elif (s > 0):
                    r -= 1
                else:
                    l += 1
        return ans
        
# @lc code=end

