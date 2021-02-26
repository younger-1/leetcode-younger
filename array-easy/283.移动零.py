#
# @lc app=leetcode.cn id=283 lang=python3
#
# [283] 移动零
#

# @lc code=start
class Solution:
    # 21/21 cases passed (40 ms)
    # Your runtime beats 77.81 % of python3 submissions
    # Your memory usage beats 6.66 % of python3 submissions (15.3 MB)
    def moveZeroes(self, nums: list[int]) -> None:
        left = 0
        for i in range(len(nums)):
            if 0 != nums[i]:
                nums[left], nums[i] = nums[i], nums[left]
                left += 1


# @lc code=end
