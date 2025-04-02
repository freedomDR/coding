#
# @lc app=leetcode.cn id=73 lang=python3
#
# [73] 矩阵置零
#

# @lc code=start
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        first_col_has_zero = False
        first_row_has_zero = False
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            if matrix[i][0] == 0:
                first_col_has_zero = True
                break
        for i in range(n):
            if matrix[0][i] == 0:
                first_row_has_zero = True
                break
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][j] == 0:
                    matrix[i][0] = matrix[0][j] = 0
        for i in range(1, m):
            for j in range(1, n):
                if matrix[i][0] == 0 or matrix[0][j] == 0:
                    matrix[i][j] = 0
        if first_col_has_zero:
            for i in range(m):
                matrix[i][0] = 0
        if first_row_has_zero:
            for i in range(n):
                matrix[0][i] = 0
        
# @lc code=end

