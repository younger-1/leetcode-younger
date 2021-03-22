#
# @lc app=leetcode.cn id=72 lang=python3
#
# [72] 编辑距离
#

# @lc code=start

# 1146/1146 cases passed (128 ms)
# Your runtime beats 90.04 % of python3 submissions
# Your memory usage beats 89.27 % of python3 submissions (17.3 MB)
class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        memo = dict()

        def dp(m: int, n: int) -> int:
            # base case
            if m == -1:
                return n + 1
            if n == -1:
                return m + 1

            if (m, n) in memo:
                return memo[m, n]

            if word1[m] == word2[n]:
                memo[m, n] = dp(m - 1, n - 1)
            else:
                memo[m, n] = min(1 + dp(m, n - 1), 1 + dp(m - 1, n), 1 + dp(m - 1, n - 1))
            return memo[m, n]

        return dp(len(word1) - 1, len(word2) - 1)


# @lc code=end
