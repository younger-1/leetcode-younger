#
# @lc app=leetcode.cn id=28 lang=python3
#
# [28] 实现 strStr()
#

# @lc code=start
class Solution:
    # 78/78 cases passed (56 ms)
    # Your runtime beats 19.28 % of python3 submissions
    # Your memory usage beats 33.95 % of python3 submissions (15 MB)
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        ptr = 0
        i = 0
        while i < len(haystack):
            if haystack[i] == needle[ptr]:
                ptr += 1
            else:
                i -= ptr
                ptr = 0
            if ptr == len(needle):
                return i - ptr + 1
            i += 1
        return -1


# @lc code=end


class Solution_1:
    def strStr(self, haystack: str, needle: str) -> int:
        h, n = len(haystack), len(needle)
        for start in range(h - n + 1):
            if haystack[start : start + n] == needle:
                return start
        return -1