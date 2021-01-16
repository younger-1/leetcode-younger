#
# @lc app=leetcode.cn id=26 lang=python3
#
# [26] 删除排序数组中的重复项
#

# @lc code=start
class Solution:
    # 161/161 cases passed (48 ms)
    # Your runtime beats 62.05 % of python3 submissions
    # Your memory usage beats 5.2 % of python3 submissions (15.9 MB)
    def removeDuplicates(self, nums: list[int]) -> int:
        cur = 0
        for i in range(len(nums) - 1):
            if nums[i] != nums[i + 1]:
                cur += 1
                nums[cur] = nums[i + 1]
        return cur + 1


# @lc code=end
