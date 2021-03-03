#
# @lc app=leetcode.cn id=304 lang=python3
#
# [304] 二维区域和检索 - 矩阵不可变
#

# @lc code=start
class NumMatrix:
    # 执行用时： 80 ms , 在所有 Python3 提交中击败了 52.88% 的用户
    # 内存消耗： 17.8 MB , 在所有 Python3 提交中击败了 21.28% 的用户
    def __init__(self, matrix: list[list[int]]):
        # Note: when matrix is None
        m, n = len(matrix), len(matrix[0]) if matrix else 0
        self.sums = [[0] * (n + 1) for _ in range(m + 1)]
        _sums = self.sums
        for i in range(m):
            for j in range(n):
                _sums[i + 1][j + 1] = _sums[i + 1][j] + _sums[i][j + 1] - _sums[i][j] + matrix[i][j]

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        m = self.sums
        return m[row2 + 1][col2 + 1] - m[row2 + 1][col1] - m[row1][col2 + 1] + m[row1][col1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
# @lc code=end
