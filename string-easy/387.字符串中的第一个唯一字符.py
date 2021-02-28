#
# @lc app=leetcode.cn id=387 lang=python3
#
# [387] 字符串中的第一个唯一字符
#

# @lc code=start
class Solution:
    # 104/104 cases passed (112 ms)
    # Your runtime beats 61.83 % of python3 submissions
    # Your memory usage beats 59.44 % of python3 submissions (15 MB)
    def firstUniqChar(self, s: str) -> int:
        position = dict()
        n = len(s)
        for i, ch in enumerate(s):
            if ch in position:
                position[ch] = -1
            else:
                position[ch] = i
        for i in range(n):
            if position[s[i]] != -1:
                return position[s[i]]
        return -1


# @lc code=end

class Solution_1(object):
    def firstUniqChar(self, s: str) -> int:
        import collections
        counter = collections.Counter(s)
        for i, ch in enumerate(s):
            if counter[ch] == 1:
                return i
        return -1
