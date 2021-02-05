#
# @lc app=leetcode.cn id=643 lang=python3
#
# [643] 子数组最大平均数 I
#

# @lc code=start
class Solution:
    # 123/123 cases passed (860 ms)
    # Your runtime beats 89.86 % of python3 submissions
    # Your memory usage beats 46.36 % of python3 submissions (18.3 MB)
    def findMaxAverage(self, nums: list[int], k: int) -> float:
        max_sum = sum(nums[:k])
        list_sum = max_sum
        for i in range(k, len(nums)):
            list_sum += nums[i] - nums[i - k]
            max_sum = max(max_sum, list_sum)
        return max_sum / k


# @lc code=end
