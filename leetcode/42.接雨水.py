#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        h_len = len(height)
        st = []
        ans = 0
        for i in range(h_len):
            while st and height[i] >= height[st[-1]]:
                mid_h = height[st.pop()]
                if (not st):
                    break
                l_h = st[-1]
                ans += (min(height[i], height[l_h])-mid_h) * (i-l_h-1)
            st.append(i)
        return ans
        
# @lc code=end

