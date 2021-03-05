/*
 * @lc app=leetcode.cn id=1162 lang=java
 *
 * [1162] 地图分析
 */

// @lc code=start

// 35/35 cases passed (19 ms)
// Your runtime beats 45.73 % of java submissions
// Your memory usage beats 32.08 % of java submissions (39.7 MB)
class Solution {
    int n;
    int[][] grid;
    
    /* 多源 BFS */
    public int maxDistance(int[][] grid) {
        this.n = grid.length;
        this.grid = grid;

        Queue<int[]> queue = new ArrayDeque<>();
        // 将所有的陆地格子加入队列
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue.add(new int[]{i, j});
                }
            }
        }

        // 如果地图上只有陆地或者海洋，返回 -1
        if (queue.isEmpty() || queue.size() == n * n) {
            return -1;
        }

        int[][] moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        // 记录当前遍历的层数（距离）
        int dist = -1;
        while (!queue.isEmpty()) {
            dist += 1;
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                int[] node = queue.poll();
                int r = node[0], c = node[1];
                for (int[] move : moves) {
                    int rr = r + move[0], cc = c + move[1];
                    if (inArea(rr, cc) && grid[rr][cc] == 0) {
                        // 对入队的海洋标记，防止其入队多次
                        grid[rr][cc] = 2;
                        queue.add(new int[]{rr, cc});
                    }
                }
            }
        }
        return dist;
    }

    boolean inArea(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
}
// @lc code=end

// 35/35 cases passed (625 ms)
// Your runtime beats 20.39 % of java submissions
// Your memory usage beats 19.79 % of java submissions (40.5 MB)
class Solution_1 {
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
    int n;
    int[][] grid;

    /* BFS */
    public int maxDistance(int[][] grid) {
        this.n = grid.length;
        this.grid = grid;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans = Math.max(ans, findNearestLand(i, j));
                }
            }
        }
        return ans;
    }

    int findNearestLand(int x, int y) {
        boolean[][] vis = new boolean[n][n];
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x, y, 0});
        vis[x][y] = true;
        while (!queue.isEmpty()) {
            int[] f = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = f[0] + dx[i];
                int ny = f[1] + dy[i];
                if (!inArea(nx, ny)) {
                    continue;
                }
                if (!vis[nx][ny]) {
                    if (grid[nx][ny] == 1) {
                        return f[2] + 1;
                    }
                    queue.offer(new int[]{nx, ny, f[2] + 1});
                    vis[nx][ny] = true;
                }
            }
        }
        return -1;
    }

    boolean inArea(int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
}

