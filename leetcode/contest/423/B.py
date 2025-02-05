import List

class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        max_len = []
        cnt = 0
        for i in range(len(nums)):
            if cnt == 0 or nums[i] > nums[i-1]:
                cnt += 1
            else:
                max_len.append(cnt)
                cnt = 0
        ans = 1
        for i in range(len(max_len)):
            ans = max(ans, max_len[i]//2)
            if i > 0:
                ans = max(ans, min(max_len[i], max_len[i-1]))
        return ans

s = Solution()
print(s.maxIncreasingSubarrays([2,5,7,8,9,2,3,4,3,1]))