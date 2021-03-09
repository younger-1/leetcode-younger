#
# @lc app=leetcode.cn id=132 lang=python3
#
# [132] 分割回文串 II
#

# @lc code=start

# 29/29 cases passed (368 ms)
# Your runtime beats 81.25 % of python3 submissions
# Your memory usage beats 40.63 % of python3 submissions (31.1 MB)
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        ioi = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                ioi[i][j] = ioi[i + 1][j - 1] and s[i] == s[j]

        mincut = [float("inf")] * n
        for i in range(n):
            if ioi[0][i]:
                mincut[i] = 0
            else:
                for j in range(i):
                    if ioi[j + 1][i]:
                        mincut[i] = min(mincut[j] + 1, mincut[i])
        return mincut[-1]


# @lc code=end
