#
# @lc app=leetcode.cn id=189 lang=python3
#
# [189] 旋转数组
#

import math

# @lc code=start
class Solution:
    # 35/35 cases passed (36 ms)
    # Your runtime beats 91.21 % of python3 submissions
    # Your memory usage beats 5.16 % of python3 submissions (15.2 MB)
    # 环状替换
    def rotate(self, nums: list[int], k: int) -> None:
        n = len(nums)
        k %= n
        count = math.gcd(k, n)
        for start in range(count):
            i = start
            pre = nums[i]
            while True:
                next = (i + k) % n
                nums[next], pre = pre, nums[next]
                i = next
                if i == start:
                    break


# @lc code=end


class Solution_0:
    # 35/35 cases passed (48 ms)
    # Your runtime beats 40.02 % of python3 submissions
    # Your memory usage beats 5.81 % of python3 submissions (15.2 MB)
    # 使用临时数组
    def rotate(self, nums: list[int], k: int) -> None:
        tmp = nums.copy()
        n = len(nums)

        def transform(i: int):
            nums[(i + k) % n] = tmp[i]

        list(map(transform, range(n)))


class Solution_1:
    # 35/35 cases passed (40 ms)
    # Your runtime beats 78.17 % of python3 submissions
    # Your memory usage beats 5.05 % of python3 submissions (15.3 MB)
    # 多次反转
    def rotate(self, nums: list[int], k: int) -> None:
        k %= len(nums)
        nums.reverse()
        nums[:k] = reversed(nums[:k])
        nums[k:] = reversed(nums[k:])