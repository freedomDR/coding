#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        d = deque()
        for i, v in enumerate(nums):
            while d and nums[d[-1]] <= v:
                d.pop()
            d.append(i)
            if i-d[0] >= k:
                d.popleft()
            if (i >= k-1):
                ans.append(nums[d[0]])
        return ans
        
# @lc code=end

