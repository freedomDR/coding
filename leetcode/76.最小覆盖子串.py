#
# @lc app=leetcode.cn id=76 lang=python3
#
# [76] 最小覆盖子串
#
from collections import defaultdict

# @lc code=start
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_map = defaultdict(int)
        for c in t: t_map[c] += 1
        flag = len(t_map.keys())
        s_map = defaultdict(int)
        ans, l = s+s, 0
        for i, c in enumerate(s):
            s_map[c] += 1
            if (s_map[c] == t_map[c]):
                flag -= 1
            if (t_map[c] == 0): continue
            while (l<i and (t_map[s[l]] == 0 or s_map[s[l]] > t_map[s[l]])):
                s_map[s[l]] -= 1
                l += 1
            if (flag == 0):
                if (len(ans) > (i-l+1)):
                    ans = s[l:i+1]
        if (len(ans) == len(s)*2):
            return ""
        else:
            return ans
        
# @lc code=end

if (__name__ == "__main__"):
    s = Solution()
    print(s.minWindow("ADOBECODEBANC", "ABC"))
    print(s.minWindow("a", "aa"))

