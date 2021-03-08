#
# @lc app=leetcode.cn id=46 lang=python3
#
# [46] 全排列
#

# @lc code=start

# 25/25 cases passed (44 ms)
# Your runtime beats 51.82 % of python3 submissions
# Your memory usage beats 8.27 % of python3 submissions (15.1 MB)
class Solution:
    # backtrack
    def permute(self, nums: list[int]) -> list[list[int]]:
        def dfs(depth):
            if depth == size:
                res.append(path[:])
                return
            for i in range(0, size):
                if not used[i]:
                    used[i] = True
                    path.append(nums[i])
                    dfs(depth + 1)
                    used[i] = False
                    path.pop()

        size = len(nums)
        res = []
        path = []
        used = [False for _ in range(size)]
        dfs(0)
        return res


# @lc code=end

# 25/25 cases passed (40 ms)
# Your runtime beats 76.05 % of python3 submissions
# Your memory usage beats 69.81 % of python3 submissions (14.9 MB)
class Solution_1:
    # backtrack
    def permute(self, nums: list[int]) -> list[list[int]]:
        def backtrack(first=0):
            if first == n:
                # Copy nums by using nums[:]
                res.append(nums[:])
            for i in range(first, n):
                nums[first], nums[i] = nums[i], nums[first]
                backtrack(first + 1)
                nums[first], nums[i] = nums[i], nums[first]

        n = len(nums)
        res = []
        backtrack()
        return res
