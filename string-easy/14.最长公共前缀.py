#
# @lc app=leetcode.cn id=14 lang=python3
#
# [14] 最长公共前缀
#

# @lc code=start
class Solution:
    # 123/123 cases passed (64 ms)
    # Your runtime beats 6.58 % of python3 submissions
    # Your memory usage beats 45.22 % of python3 submissions (14.9 MB)
    def longestCommonPrefix(self, strs: list[str]) -> str:
        # 纵向扫描
        if not strs:
            return ""
        length, count = len(strs[0]), len(strs)
        for i in range(length):
            c = strs[0][i]
            if any(len(strs[j]) == i or strs[j][i] != c for j in range(1, count)):
                return strs[0][:i]
        return strs[0]


# @lc code=end


class Solution_0:
    # 执行用时： 40 ms , 在所有 Python3 提交中击败了 71.75% 的用户
    # 内存消耗： 15 MB , 在所有 Python3 提交中击败了 32.47% 的用户
    def longestCommonPrefix(self, strs: list[str]) -> str:
        def in_common(s: str) -> bool:
            return all(map(lambda x: x.find(s) == 0, strs))

        if len(strs) == 0:
            return ""
        res = ""
        for i in range(len(strs[0])):
            if in_common(res + strs[0][i]):
                res += strs[0][i]
            else:
                break
        return res


class Solution_1:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        def lcp(start, end):
            if start == end:
                return strs[start]

            mid = (start + end) // 2
            # Recursion
            # post-order traversal
            lcpLeft, lcpRight = lcp(start, mid), lcp(mid + 1, end)
            minLength = min(len(lcpLeft), len(lcpRight))
            for i in range(minLength):
                if lcpLeft[i] != lcpRight[i]:
                    return lcpLeft[:i]

            return lcpLeft[:minLength]

        return "" if not strs else lcp(0, len(strs) - 1)
