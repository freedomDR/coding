#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p_map = defaultdict(int)
        for c in p:
            p_map[c] += 1
        s_map = defaultdict(int)
        ans = []
        for i, c in enumerate(s):
            s_map[c] += 1
            if (i>=len(p)):
                s_map[s[i-len(p)]] -= 1
            # print(i, s_map)
            ok = True
            for v in p_map.keys():
                if (p_map[v] != s_map[v]):
                    ok = False
                    break
            if (ok):
                ans.append(i-len(p)+1)
        return ans
        
# @lc code=end

