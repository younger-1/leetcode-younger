#
# @lc app=leetcode.cn id=1047 lang=python3
#
# [1047] 删除字符串中的所有相邻重复项
#

# @lc code=start

# 98/98 cases passed (56 ms)
# Your runtime beats 99.17 % of python3 submissions
# Your memory usage beats 28.4 % of python3 submissions (15.3 MB)
class Solution:
    # Stack
    def removeDuplicates(self, S: str) -> str:
        stk = []
        for ch in S:
            if stk and stk[-1] == ch:
                stk.pop()
            else:
                stk.append(ch)
        return "".join(stk)


# @lc code=end

# 执行用时： 116 ms , 在所有 Python3 提交中击败了 16.73% 的用户
# 内存消耗： 15.1 MB , 在所有 Python3 提交中击败了 72.24% 的用户
class Solution_0:
    def removeDuplicates(self, S: str) -> str:
        i = 0
        while i < len(S) - 1:
            if S[i] != S[i + 1]:
                i += 1
            else:
                S = S[0:i] + S[i + 2 :]
                if i > 0:
                    i = i - 1
        return S
