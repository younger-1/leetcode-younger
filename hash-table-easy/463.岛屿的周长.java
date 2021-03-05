/*
 * @lc app=leetcode.cn id=463 lang=java
 *
 * [463] 岛屿的周长
 */

// @lc code=start

// 5833/5833 cases passed (10 ms)
// Your runtime beats 51.12 % of java submissions
// Your memory usage beats 22.7 % of java submissions (40.1 MB)
class Solution {
    public int islandPerimeter(int[][] grid) {
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 1) {
                    return dfs(grid, r, c);
                }
            }
        }
        return 0;
    }

    int dfs(int[][] grid, int r, int c) {
        if (!this.inArea(grid, r, c)) {
            return 1;
        }
        if (grid[r][c] == 0) {
            return 1;
        }
        if (grid[r][c] == 2) {
            return 0;
        }
        grid[r][c] = 2;
        return dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }

    boolean inArea(int[][] grid, int r, int c) {
        return 0 <= r && r < grid.length && 0 <= c && c < grid[0].length;
    }
}
// @lc code=end

