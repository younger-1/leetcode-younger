#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 外观数列
#

# @lc code=start
class Solution:
    # 30/30 cases passed (48 ms)
    # Your runtime beats 90.81 % of python3 submissions
    # Your memory usage beats 44.65 % of python3 submissions (14.9 MB)
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        pre_say = self.countAndSay(n - 1)
        pre = pre_say[0]
        num = 0
        res = ""
        for ch in pre_say:
            if pre != ch:
                res += str(num) + pre
                pre = ch
                num = 1
            else:
                num += 1
        res += str(num) + pre
        return res


# @lc code=end
