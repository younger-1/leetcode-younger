#
# @lc app=leetcode.cn id=217 lang=python3
#
# [217] 存在重复元素
#

# @lc code=start
class Solution:
    # 执行用时： 52 ms , 在所有 Python3 提交中击败了 30.04% 的用户
    # 内存消耗： 20.2 MB , 在所有 Python3 提交中击败了 24.53% 的用户
    def containsDuplicate(self, nums: list[int]) -> bool:
        return len(set(nums)) < len(nums)


# @lc code=end
