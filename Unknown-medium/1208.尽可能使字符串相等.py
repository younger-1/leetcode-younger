#
# @lc app=leetcode.cn id=1208 lang=python3
#
# [1208] 尽可能使字符串相等
#
# @lc code=start
class Solution:
    # 37/37 cases passed (84 ms)
    # Your runtime beats 83.72 % of python3 submissions
    # Your memory usage beats 94.96 % of python3 submissions (15 MB)
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        left = 0
        cost = 0
        for i in range(len(s)):
            cost += abs(ord(s[i]) - ord(t[i]))
            if cost > maxCost:
                cost -= abs(ord(s[left]) - ord(t[left]))
                left += 1
        return len(s) - left


# @lc code=end
