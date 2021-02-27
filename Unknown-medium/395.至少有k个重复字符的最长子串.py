#
# @lc app=leetcode.cn id=395 lang=python3
#
# [395] 至少有K个重复字符的最长子串
#

# @lc code=start
class Solution:
    # 31/31 cases passed (36 ms)
    # Your runtime beats 92.03 % of python3 submissions
    # Your memory usage beats 52.05 % of python3 submissions (15 MB)
    def longestSubstring(self, s: str, k: int) -> int:
        if not s:
            return 0
        for c in set(s):
            if s.count(c) < k:
                return max(self.longestSubstring(t, k) for t in s.split(c))
        return len(s)


# @lc code=end
