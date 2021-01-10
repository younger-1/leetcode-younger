#
# @lc app=leetcode.cn id=830 lang=python3
#
# [830] 较大分组的位置
#


# @lc code=start
class Solution:
    # 202/202 cases passed (36 ms)
    # Your runtime beats 93.89 % of python3 submissions
    # Your memory usage beats 36.33 % of python3 submissions (14.9 MB)
    def largeGroupPositions(self, s: str) -> list[list[int]]:
        res = []
        left, right = 0, 0
        while right < len(s):
            while right < len(s) and s[left] == s[right]:
                right += 1
            if left + 3 <= right:
                res.append([left, right - 1])
            left = right
        return res


# @lc code=end
