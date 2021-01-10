#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#

from typing import List

# @lc code=start
class Solution:
    # 52/52 cases passed (36 ms)
    # Your runtime beats 89.99 % of python3 submissions
    # Your memory usage beats 15.42 % of python3 submissions (15 MB)
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = dict()
        for i, n in enumerate(nums):
            if target - n in table:
                return [table[target - n], i]
            table[n] = i
        return []


# @lc code=end
