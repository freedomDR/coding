#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#

# @lc code=start
class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        ans = []
        sort_intervals = sorted(intervals)
        max_r = -1
        for v in sort_intervals:
            assert(len(v) == 2)
            l, r = v
            if (max_r < l):
                ans.append(v)
                max_r = r
            else:
                max_r = max(max_r, r)
                ans[-1][-1] = max_r
        return ans
        
# @lc code=end

