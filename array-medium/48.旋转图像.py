#
# @lc app=leetcode.cn id=48 lang=python3
#
# [48] 旋转图像
#

# @lc code=start
class Solution:
    # 21/21 cases passed (36 ms)
    # Your runtime beats 81.63 % of python3 submissions
    # Your memory usage beats 85.86 % of python3 submissions (14.6 MB)
    def rotate(self, matrix: list[list[int]]) -> None:
        # 分为 h*w 的子块，共 4 个子块
        h = len(matrix) // 2
        w = len(matrix) - h
        if h < 1:
            return
        for i in range(h):
            for j in range(w):
                i_new, j_new = i, j
                # 交换 3 次
                for _ in range(3):
                    # [x,y] 旋转 90 度为 [-y,x], 这里需要先平移一下
                    i_new, j_new = j_new, (len(matrix) - 1) - i_new
                    matrix[i][j], matrix[i_new][j_new] = matrix[i_new][j_new], matrix[i][j]


# @lc code=end


class Solution_1:
    # 顺时针旋转90度=主对角线翻转+左右翻转
    def rotate(self, matrix: list[list[int]]) -> None:
        n = len(matrix)
        for i in range(n):
            for j in range(i + 1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        for i in range(n):
            for j in range(n // 2):
                matrix[i][j], matrix[i][n - j - 1] = matrix[i][n - j - 1], matrix[i][j]