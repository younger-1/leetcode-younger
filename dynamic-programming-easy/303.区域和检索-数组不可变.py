#
# @lc app=leetcode.cn id=303 lang=python3
#
# [303] 区域和检索 - 数组不可变
#

# @lc code=start
class NumArray:
    # 16/16 cases passed (64 ms)
    # Your runtime beats 91.28 % of python3 submissions
    # Your memory usage beats 8.48 % of python3 submissions (18.2 MB)
    def __init__(self, nums: list[int]):
        self.sums = [0]
        for num in nums:
            self.sums.append(self.sums[-1] + num)

    def sumRange(self, i: int, j: int) -> int:
        return self.sums[j + 1] - self.sums[i]


# @lc code=end


class NumArray_0:
    # 执行用时： 944 ms , 在所有 Python3 提交中击败了 31.68% 的用户
    # 内存消耗： 18 MB , 在所有 Python3 提交中击败了 48.34% 的用户
    def __init__(self, nums: list[int]):
        self._list = nums

    def sumRange(self, i: int, j: int) -> int:
        return sum(self._list[i : j + 1])
