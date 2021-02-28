#
# @lc app=leetcode.cn id=242 lang=python3
#
# [242] 有效的字母异位词
#

# @lc code=start
class Solution:
    # 34/34 cases passed (56 ms)
    # Your runtime beats 65.81 % of python3 submissions
    # Your memory usage beats 18.6 % of python3 submissions (15.1 MB)
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        table = dict()
        for x, y in zip(s, t):
            if x not in table:
                table[x] = 1
            else:
                table[x] += 1
            if y not in table:
                table[y] = -1
            else:
                table[y] -= 1
        return all(map(lambda key: table[key] == 0, table.keys()))


# @lc code=end
class Solution_0:
    # 34/34 cases passed (84 ms)
    # Your runtime beats 6.74 % of python3 submissions
    # Your memory usage beats 11.98 % of python3 submissions (15.2 MB)
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        li = [0 for _ in range(26)]
        for i in range(len(s)):
            li[ord(s[i]) - ord("a")] += 1
            li[ord(t[i]) - ord("a")] -= 1
        return all(map(lambda x: x == 0, li))
