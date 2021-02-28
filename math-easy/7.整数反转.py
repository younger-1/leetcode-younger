#
# @lc app=leetcode.cn id=7 lang=python3
#
# [7] 整数反转
#

# @lc code=start
class Solution:
    # 1032/1032 cases passed (40 ms)
    # Your runtime beats 75.49 % of python3 submissions
    # Your memory usage beats 22.33 % of python3 submissions (14.9 MB)
    def reverse(self, x: int) -> int:
        rev = 0
        num = abs(x)
        boundry = (1 << 31) - 1 if x > 0 else (1 << 31)
        while num != 0:
            # num, mod = divmod(num, 10)
            # rev = rev * 10 + mod
            rev = rev * 10 + num % 10
            if rev > boundry:
                return 0
            num //= 10
        return rev if x > 0 else -rev


# @lc code=end

# python 负数的余数也是正数
# rev = 0
# while x != 0:
#     x, mod = divmod(x, 10)
#     rev = rev * 10 + mod


class Solution_1:
    # 1032/1032 cases passed (44 ms)
    # Your runtime beats 51.7 % of python3 submissions
    # Your memory usage beats 61.22 % of python3 submissions (14.7 MB)
    def reverse(self, x: int) -> int:
        str_x = str(x)
        if str_x[0] != "-":
            str_x = str_x[::-1]
            x = int(str_x)
        else:
            str_x = str_x[:0:-1]
            x = -int(str_x)
        return x if -(2 ** 31) < x < 2 ** 31 - 1 else 0