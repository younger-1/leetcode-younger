#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

import math
from collections import deque


# @lc code=start

lio = []
# @lc code=end


# @暴力递归
class Solution1(object):
    def numSquares(self, n):
        square_nums = [i ** 2 for i in range(1, int(math.sqrt(n)) + 1)]

        def minNumSquares(k):
            """ recursive solution """
            # bottom cases: find a square number
            if k in square_nums:
                return 1
            min_num = float("inf")
            # Find the minimal value among all possible solutions
            for square in square_nums:
                if k < square:
                    break
                new_num = minNumSquares(k - square) + 1
                min_num = min(min_num, new_num)
            return min_num

        return minNumSquares(n)


# 5248ms 13.8MB
# @DP
class Solution2:
    def numSquares(self, n: int) -> int:
        square_nums = [i ** 2 for i in range(1, int(math.sqrt(n)) + 1)]
        dp = [float("inf")] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            for square in square_nums:
                if i < square:
                    break
                dp[i] = min(dp[i], dp[i - square] + 1)

        return dp[-1]


# 76ms 14.3MB
# @贪心枚举
class Solution3:
    def numSquares(self, n):
        def is_divided_by(n, count):
            """
                return: true if "n" can be decomposed into "count" number of perfect square numbers.
                e.g. n=12, count=3:  true.
                     n=12, count=2:  false
            """
            if count == 1:
                return n in square_nums
            for k in square_nums:
                if is_divided_by(n - k, count - 1):
                    return True
            return False

        square_nums = set([i * i for i in range(1, int(n ** 0.5) + 1)])
        for count in range(1, n + 1):
            if is_divided_by(n, count):
                return count


# 200-296ms 14.8MB
# @BFS
class Solution4:
    def numSquares(self, n):

        square_nums = [i * i for i in range(1, int(n ** 0.5) + 1)]
        level = 0
        queue = {n}
        while queue:
            level += 1
            # use set() instead of list() to eliminate the redundancy,
            # which would even provide a 5-times speedup, 200ms vs. 1000ms.
            next_queue = set()
            for q in queue:
                for square in square_nums:
                    if q == square:
                        return level
                    elif q < square:
                        break
                    else:
                        next_queue.add(q - square)

            queue = next_queue

        return 0


# 380ms 14.6MB
# @BFS
class Solution4_1:
    def numSquares(self, n: int) -> int:
        deq = deque()
        visited = set()
        deq.append((n, 0))
        while deq:
            number, step = deq.popleft()
            targets = [number - i * i for i in range(1, int(number ** 0.5) + 1)]
            for target in targets:
                if target == 0:
                    return step + 1
                if target not in visited:
                    deq.append((target, step + 1))
                    visited.add(target)
        return -1


# 48ms 13.5MB
# @math
class Solution5:
    def isSquare(self, n: int) -> bool:
        sq = int(math.sqrt(n))
        return sq * sq == n

    def numSquares(self, n: int) -> int:

        if self.isSquare(n):
            return 1

        # four-square and three-square theorems
        while (n & 3) == 0:  # n % 4 == 0
            n >>= 2  # reducing the 4^k factor from number
        if (n & 7) == 7:  # n % 8 == 7
            return 4

        # check if the number can be decomposed into sum of two squares
        for i in range(1, int(n ** (0.5)) + 1):
            if self.isSquare(n - i * i):
                return 2
        # bottom case from the three-square theorem
        return 3
