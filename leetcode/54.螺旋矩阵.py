#
# @lc app=leetcode.cn id=54 lang=python3
#
# [54] 螺旋矩阵
#

# @lc code=start
class Solution:
    
    offset = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    
    def dfs(self, matrix, ans, i, j, pre_offset_pos):
        for x in range(pre_offset_pos, pre_offset_pos + 4):
            next_i, next_j = i + self.offset[x%4][0], j + self.offset[x%4][1]
            if 0 <= next_i < len(matrix) and 0 <= next_j < len(matrix[0]) and matrix[next_i][next_j] != None:
                ans.append(matrix[next_i][next_j])
                matrix[next_i][next_j] = None
                self.dfs(matrix, ans, next_i, next_j, x)
                break
            
    
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ans = []
        self.dfs(matrix, ans, 0, -1, 0)
        return ans

        
        
        
# @lc code=end

