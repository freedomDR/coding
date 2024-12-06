#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans, l, s_set = 0, 0, set()
        for v in s:
            while (v in s_set):
                s_set.remove(s[l])
                l += 1
            s_set.add(v)
            ans = max(ans, len(s_set))
        return ans
        
# @lc code=end

