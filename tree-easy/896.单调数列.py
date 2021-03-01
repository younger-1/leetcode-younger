#
# @lc app=leetcode.cn id=896 lang=python3
#
# [896] 单调数列
#

# @lc code=start
class Solution:
    # 366/366 cases passed (536 ms)
    # Your runtime beats 47.11 % of python3 submissions
    # Your memory usage beats 85.26 % of python3 submissions (20.7 MB)
    def isMonotonic(self, A: list[int]) -> bool:
        inc, dec = False, False
        for i in range(len(A) - 1):
            if A[i] < A[i + 1]:
                inc = True
            if A[i] > A[i + 1]:
                dec = True
        return not (inc and dec)


# @lc code=end


class Solution_0:
    # 执行用时： 520 ms , 在所有 Python3 提交中击败了 63.13% 的用户
    # 内存消耗： 21 MB , 在所有 Python3 提交中击败了 17.16% 的用户
    def isMonotonic(self, A: list[int]) -> bool:
        if len(A) < 2:
            return True
        init = 0
        while init + 1 < len(A) and A[init] - A[init + 1] == 0:
            init += 1
        if init + 1 == len(A):
            return True
        diff = A[init] - A[init + 1]
        for i in range(init, len(A) - 1):
            if (A[i] - A[i + 1]) * diff < 0:
                return False
        return True
