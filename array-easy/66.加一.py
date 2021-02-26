#
# @lc app=leetcode.cn id=66 lang=python3
#
# [66] 加一
#

# @lc code=start
class Solution:
    # 执行用时： 44 ms , 在所有 Python3 提交中击败了 30.18% 的用户
    # 内存消耗： 15 MB , 在所有 Python3 提交中击败了 5.11% 的用户
    def plusOne(self, digits: list[int]) -> list[int]:
        res = 0
        for i in digits:
            res = res * 10 + i
        res += 1
        res_list = []
        while res > 0:
            res, mod = divmod(res, 10)
            res_list.insert(0, mod)
        return res_list


# @lc code=end
