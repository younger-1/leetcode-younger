#
# @lc app=leetcode.cn id=131 lang=python3
#
# [131] 分割回文串
#

# @lc code=start

# 执行用时： 120 ms , 在所有 Python3 提交中击败了 85.30% 的用户
# 内存消耗： 31 MB , 在所有 Python3 提交中击败了 55.26% 的用户
# 32/32 cases passed (120 ms)
# Your runtime beats 85.67 % of python3 submissions
# Your memory usage beats 59.02 % of python3 submissions (30.9 MB)
class Solution:
    def partition(self, s: str) -> list[list[str]]:
        n = len(s)
        f = [[True] * n for _ in range(n)]

        # for j in range(n):
        #     for i in range(j):
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                f[i][j] = (s[i] == s[j]) and f[i + 1][j - 1]

        ret = []
        ans = []

        def dfs(i: int):
            if i == n:
                ret.append(ans[:])
                return

            for j in range(i, n):
                if f[i][j]:
                    ans.append(s[i : j + 1])
                    dfs(j + 1)
                    ans.pop()

        dfs(0)
        return ret


# @lc code=end
