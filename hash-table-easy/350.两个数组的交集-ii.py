#
# @lc app=leetcode.cn id=350 lang=python3
#
# [350] 两个数组的交集 II
#


from collections import defaultdict

# @lc code=start
class Solution:
    # 61/61 cases passed (56 ms)
    # Your runtime beats 75.58 % of python3 submissions
    # Your memory usage beats 25.61 % of python3 submissions (15 MB)
    def intersect(self, nums1: list[int], nums2: list[int]) -> list[int]:
        table = defaultdict(int)
        for i in nums1:
            table[i] += 1
        res = []
        for i in nums2:
            if i in table and table[i] != 0:
                table[i] -= 1
                res.append(i)
        return res


# @lc code=end
