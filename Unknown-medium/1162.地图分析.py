#
# @lc app=leetcode.cn id=1162 lang=python3
#
# [1162] 地图分析
#

# @lc code=start

# Time Limit Exceeded
class Solution:
    def __init__(self):
        self.dx = [0, 1, 0, -1]
        self.dy = [1, 0, -1, 0]

    def maxDistance(self, grid: list[list[int]]) -> int:
        self.n = len(grid)
        self.grid = grid
        ans = -1
        for i in range(self.n):
            for j in range(self.n):
                if grid[i][j] == 0:
                    ans = max(ans, self.findNearestLand(i, j))
        return ans

    def inArea(self, x: int, y: int) -> bool:
        return 0 <= x < self.n and 0 <= y < self.n

    def findNearestLand(self, x: int, y: int) -> int:
        visited = [[False] * self.n for _ in range(self.n)]
        # (row, col, dist)
        queue = [(x, y, 0)]
        visited[x][y] = True
        while queue:
            f = queue.pop(0)
            for i in range(4):
                nx, ny = f[0] + self.dx[i], f[1] + self.dy[i]
                if not self.inArea(nx, ny):
                    continue
                if not visited[nx][ny]:
                    if self.grid[nx][ny] == 1:
                        return f[2] + 1
                    queue.append((nx, ny, f[2] + 1))
                    visited[nx][ny] = True
        return -1


# @lc code=end

# Time Limit Exceeded
class Solution_0:
    def maxDistance(self, grid: list[list[int]]) -> int:
        self.n = len(grid)
        self.grid = grid

        # All cell are land
        res = -1
        for r, row in enumerate(grid):
            for c, val in enumerate(row):
                if val == 0:
                    res = max(res, self.bfs(r, c))
        return res

    def inArea(self, x: int, y: int) -> bool:
        return 0 <= x < self.n and 0 <= y < self.n

    def bfs(self, r: int, c: int) -> int:
        dist = -1
        queue = [(r, c)]
        visited = [[False] * self.n for _ in range(self.n)]
        while queue:
            dist += 1
            for _ in range(len(queue)):
                # Use append() and pop(0) as EnQueue and DeQueue
                x, y = queue.pop(0)
                for i, j in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                    xx, yy = x + i, y + j
                    if self.inArea(xx, yy):
                        if visited[xx][yy] is True:
                            continue
                        visited[xx][yy] = True
                        if self.grid[xx][yy] == 1:
                            return dist + 1
                        queue.append((xx, yy))
        # All cell are ocean
        return -1
