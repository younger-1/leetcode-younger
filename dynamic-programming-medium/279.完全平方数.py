#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

# @lc code=start

# 588/588 cases passed (76 ms)
# Your runtime beats 92.99 % of python3 submissions
# Your memory usage beats 30.47 % of python3 submissions (15.2 MB)

# @Greedy
class Solution:
    def numSquares(self, n: int) -> int:
        square_nums = {i ** 2 for i in range(1, int(n ** 0.5) + 1)}

        def divisible(n, count):
            if count == 1:
                return n in square_nums
            for val in square_nums:
                if divisible(n - val, count - 1):
                    return True
            return False

        for count in range(1, n + 1):
            if divisible(n, count):
                return count


# @lc code=end

# 588/588 cases passed (204 ms)
# Your runtime beats 86.06 % of python3 submissions
# Your memory usage beats 23.22 % of python3 submissions (15.4 MB)

# @BFS
class Solution_1:
    def numSquares(self, n: int) -> int:
        square_nums = [i ** 2 for i in range(1, int(n ** 0.5) + 1)][::-1]
        queue = [n]
        cache = {n: 1}
        while queue:
            val = queue.pop(0)
            if val in square_nums:
                return cache[val]
            for num in square_nums:
                x = val - num
                if x < 0 or x in cache:
                    continue
                queue.append(x)
                cache[x] = cache[val] + 1
