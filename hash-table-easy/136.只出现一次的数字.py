#
# @lc app=leetcode.cn id=136 lang=python3
#
# [136] 只出现一次的数字
#

# @lc code=start
class Solution:
    # 61/61 cases passed (48 ms)
    # Your runtime beats 77.41 % of python3 submissions
    # Your memory usage beats 5.19 % of python3 submissions (16.6 MB)
    def singleNumber(self, nums: list[int]) -> int:
        from functools import reduce

        return reduce(lambda x, y: x ^ y, nums)


# @lc code=end


class Solution_0:
    # 61/61 cases passed (40 ms)
    # Your runtime beats 96.62 % of python3 submissions
    # Your memory usage beats 5.18 % of python3 submissions (16.7 MB)
    def singleNumber(self, nums: list[int]) -> int:
        return sum(set(nums)) * 2 - sum(nums)


class Solution_1:
    # 61/61 cases passed (44 ms)
    # Your runtime beats 89.69 % of python3 submissions
    # Your memory usage beats 5.19 % of python3 submissions (16.6 MB)
    def singleNumber(self, nums: list[int]) -> int:
        res = set()
        for i in nums:
            if i in res:
                res.remove(i)
            else:
                res.add(i)
        return res.pop()
