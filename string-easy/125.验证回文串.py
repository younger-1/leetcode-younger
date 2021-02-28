#
# @lc app=leetcode.cn id=125 lang=python3
#
# [125] 验证回文串
#

# @lc code=start
class Solution:
    # 480/480 cases passed (56 ms)
    # Your runtime beats 65.35 % of python3 submissions
    # Your memory usage beats 10.63 % of python3 submissions (20.1 MB)
    def isPalindrome(self, s: str) -> bool:
        sgood = "".join(ch.lower() for ch in s if ch.isalnum())
        return sgood == sgood[::-1]


# @lc code=end


class Solution_0:
    # 480/480 cases passed (100 ms)
    # Your runtime beats 5.16 % of python3 submissions
    # Your memory usage beats 74.82 % of python3 submissions (14.9 MB)
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and (
                ord(s[l]) < ord("0")
                or ord("9") < ord(s[l]) < ord("A")
                or ord("Z") < ord(s[l]) < ord("a")
                or ord(s[l]) > ord("z")
            ):
                l += 1
            while l < r and (
                ord(s[r]) < ord("0")
                or ord("9") < ord(s[r]) < ord("A")
                or ord("Z") < ord(s[r]) < ord("a")
                or ord(s[r]) > ord("z")
            ):
                r -= 1
            if s[l] == s[r] or (
                ord(s[l]) >= ord("A")
                and ord(s[r]) >= ord("A")
                and abs(ord(s[l]) - ord(s[r])) == ord("a") - ord("A")
            ):
                l += 1
                r -= 1
                continue
            return False
        return True
