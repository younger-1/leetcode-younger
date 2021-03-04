/*
 * @lc app=leetcode.cn id=695 lang=java
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start

// 726/726 cases passed (3 ms)
// Your runtime beats 78.66 % of java submissions
// Your memory usage beats 80.25 % of java submissions (38.9 MB)
class Solution {
    /* DFS */
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                int a = this.area(grid, r, c);
                res = Math.max(res, a);
            }
        }
        return res;
    }

    int area(int[][] grid, int r, int c) {
        if (!this.inArea(grid, r, c)) {
            return 0;
        }

        if (grid[r][c] != 1) {
            return 0;
        }
        grid[r][c] = 2;

        return 1 + area(grid, r + 1, c)
                 + area(grid, r - 1, c)
                 + area(grid, r, c + 1)
                 + area(grid, r, c - 1);
    }
    
    boolean inArea(int[][] grid, int r, int c) {
        return 0 <= r && r < grid.length && 0 <= c && c < grid[0].length;
    }
}
// @lc code=end

