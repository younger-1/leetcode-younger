#
# @lc app=leetcode.cn id=778 lang=python3
#
# [778] 水位上升的泳池中游泳
#

# @lc code=start

# 并查集
class Solution:
    # 41/41 cases passed (156 ms)
    # Your runtime beats 63.81 % of python3 submissions
    # Your memory usage beats 77.85 % of python3 submissions (15.3 MB)
    def swimInWater(self, grid: list[list[int]]) -> int:
        n = len(grid)
        self.f = [i for i in range(n ** 2)]
        pos = [[0, 0] for _ in range(n ** 2)]
        for i in range(n):
            for j in range(n):
                pos[grid[i][j]][0] = i
                pos[grid[i][j]][1] = j

        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        for threshold in range(n ** 2):
            i, j = pos[threshold][0], pos[threshold][1]
            for dire in directions:
                ni, nj = i + dire[0], j + dire[1]
                if 0 <= ni < n and 0 <= nj < n and grid[ni][nj] <= threshold:
                    self.merge(i * n + j, ni * n + nj)
            if self.find(0) == self.find(n ** 2 - 1):
                return threshold

    def merge(self, i, j):
        fi = self.find(i)
        fj = self.find(j)
        self.f[fi] = fj

    def find(self, i) -> int:
        if self.f[i] != i:
            self.f[i] = self.find(self.f[i])
        return self.f[i]


# @lc code=end

# 二分查找
class Solution_0:
    # 41/41 cases passed (324 ms)
    # Your runtime beats 11.89 % of python3 submissions
    # Your memory usage beats 95.32 % of python3 submissions (14.9 MB)
    def swimInWater(self, grid: list[list[int]]) -> int:
        self.grid = grid
        n = len(grid)
        left, right = 0, n ** 2 - 1
        while left < right:
            mid = (left + right) // 2
            if self.check(mid):
                right = mid
            else:
                left = mid + 1
        return left

    def check(self, threshold: int) -> bool:
        if self.grid[0][0] > threshold:
            return False
        n = len(self.grid)
        # ! Wrong: visited = [[0] * n] * n
        visited = [[0 for _ in range(n)] for _ in range(n)]
        lis = list([[0, 0]])
        visited[0][0] = 1
        directions = ((0, 1), (0, -1), (1, 0), (-1, 0))
        while lis:
            pos = lis.pop(0)
            i, j = pos
            for dire in directions:
                i_ = i + dire[0]
                j_ = j + dire[1]
                if 0 <= i_ < n and 0 <= j_ < n:
                    if 0 == visited[i_][j_] and self.grid[i_][j_] <= threshold:
                        lis.append([i_, j_])
                        visited[i_][j_] = 1
        return bool(visited[n - 1][n - 1])
