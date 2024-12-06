#
# @lc app=leetcode.cn id=560 lang=python3
#
# [560] 和为 K 的子数组
#

# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = defaultdict(int)
        mp[0] = 1
        ans, tmp_sum = 0, 0
        
        for i, v in enumerate(nums):
            tmp_sum += v
            ans += mp[tmp_sum-k]
            mp[tmp_sum] += 1
        return ans
        
# @lc code=end

