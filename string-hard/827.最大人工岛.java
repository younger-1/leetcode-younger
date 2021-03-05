/*
 * @lc app=leetcode.cn id=827 lang=java
 *
 * [827] 最大人工岛
 */

// @lc code=start

// 75/75 cases passed (220 ms)
// Your runtime beats 25.47 % of java submissions
// Your memory usage beats 7.37 % of java submissions (78.2 MB)
class Solution {
    public int largestIsland(int[][] grid) {
        List<Integer> areaOfIsland = new ArrayList<Integer>(List.of(0, 0));
        // 0 is ocean, 1 is land. Let idx starts from 2 to avoid conflict
        int idx = 2;
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                areaOfIsland.add(this.area(idx, grid, r, c));
                idx++;
            }
        }
        // int res = 0 is not good. When all cell are land, it will return 0 directly 
        int res = areaOfIsland.stream().max(Integer::compareTo).get();
        for (int r = 0; r < grid.length; r++) {
            for (int c = 0; c < grid[0].length; c++) {
                if (grid[r][c] == 0) {
                    int jointArea = this.jointArea(grid, areaOfIsland, r, c);
                    res = Math.max(res, jointArea);
                }
            }
        }
        return res;
    }

    int area(int idx, int[][] grid, int r, int c) {
        if (!this.inArea(grid, r, c)) {
            return 0;
        }
        if (grid[r][c] != 1) {
            return 0;
        }
        // Every cell of grid is set to index of areaOfIsland representing the island that this cell belongs to.
        grid[r][c] = idx;
        return 1 + area(idx, grid, r + 1, c)
                 + area(idx, grid, r - 1, c)
                 + area(idx, grid, r, c + 1)
                 + area(idx, grid, r, c - 1);
    }

    boolean inArea(int[][] grid, int r, int c) {
        return 0 <= r && r < grid.length && 0 <= c && c < grid[0].length;
    }

    int jointArea(int[][] grid, List<Integer> areaOfIsland, int r, int c) {
        Set<Integer> islands = new HashSet<>();
        addIsland(islands, grid, r + 1, c);
        addIsland(islands, grid, r - 1, c);
        addIsland(islands, grid, r, c + 1);
        addIsland(islands, grid, r, c - 1);
        return 1 + islands.stream().map(x -> areaOfIsland.get(x)).reduce(0, (a, b) -> a + b);
        // int res = 1;
        // for (int idx : islands) {
        //     res += areaOfIsland.get(idx);
        // }
        // return res;
    }

    void addIsland(Set<Integer> islands, int[][] grid,int r, int c) {
        if (this.inArea(grid, r, c)) {
            islands.add(grid[r][c]);
        }
    }
}
// @lc code=end

