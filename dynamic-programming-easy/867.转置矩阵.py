#
# @lc app=leetcode.cn id=867 lang=python3
#
# [867] 转置矩阵
#

# @lc code=start
class Solution:
    # 执行用时：40 ms, 在所有 Python3 提交中击败了 98.99% 的用户
    # 内存消耗：15.3 MB, 在所有 Python3 提交中击败了 42.42% 的用户
    def transpose(self, matrix: list[list[int]]) -> list[list[int]]:
        x = []
        for i in range(len(matrix[0])):
            x.append([vec[i] for vec in matrix])
        return x


# @lc code=end
