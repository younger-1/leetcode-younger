#
# @lc app=leetcode.cn id=832 lang=python3
#
# [832] 翻转图像
#

# @lc code=start
class Solution:
    # 82/82 cases passed (28 ms)
    # Your runtime beats 100 % of python3 submissions
    # Your memory usage beats 5.09 % of python3 submissions (15.1 MB)
    def flipAndInvertImage(self, A: list[list[int]]) -> list[list[int]]:
        # return [list(map(lambda i: 0 if i else 1, x[::-1])) for x in A]
        # return [list(map(lambda i: i ^ 1, x[::-1])) for x in A]
        return [[i ^ 1 for i in x[::-1]] for x in A]


# @lc code=end
