#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#

import re

# @lc code=start
class Solution:
    # 1082/1082 cases passed (48 ms)
    # Your runtime beats 43.22 % of python3 submissions
    # Your memory usage beats 42.88 % of python3 submissions (14.9 MB)
    def myAtoi(self, s: str) -> int:
        return max(min(int(*re.findall(r"^[\+\-]?\d+", s.lstrip())), 2 ** 31 - 1), -(2 ** 31))


# @lc code=end

class Solution_1:
    def myAtoi(self, str: str) -> int:
        str = str.lstrip()  # 清除左边多余的空格
        num_re = re.compile(r"^[\+\-]?\d+")  # 设置正则规则
        num = num_re.findall(str)  # 查找匹配的内容
        num = int(*num)  # 由于返回的是个列表，解包并且转换成整数
        return max(min(num, 2 ** 31 - 1), -(2 ** 31))  # 返回值

