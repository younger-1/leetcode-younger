#
# @lc app=leetcode.cn id=409 lang=python3
#
# [409] 最长回文串
#

# @lc code=start
class Solution:
    # 95/95 cases passed (48 ms)
    # Your runtime beats 22.55 % of python3 submissions
    # Your memory usage beats 63.59 % of python3 submissions (14.8 MB)
    def longestPalindrome(self, s: str) -> int:
        import collections

        cnt = collections.Counter(s)
        res = 0
        for c in cnt.values():
            res += (c // 2) * 2
            if res % 2 == 0 and c % 2 == 1:
                res += 1
        return res


# @lc code=end


class Solution_1:
    # 95/95 cases passed (36 ms)
    # Your runtime beats 87.79 % of python3 submissions
    # Your memory usage beats 23.44 % of python3 submissions (14.9 MB)
    def longestPalindrome(self, s: str) -> int:
        import collections

        cnt = collections.Counter(s)
        res = 0
        for c in cnt.values():
            res += c - (c & 1)
        return res if res == len(s) else res + 1