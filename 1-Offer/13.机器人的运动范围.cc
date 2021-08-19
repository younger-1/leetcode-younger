// 剑指 Offer 13. 机器人的运动范围
// https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/

#include <queue>
#include <vector>

using namespace std;

// @DFS
class Solution {
   public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return dfs(0, 0, m, n, k, visited);
    }

   private:
    int dfs(int i, int j, int m, int n, int k, vector<vector<bool>>& visited) {
        // 1 <= n,m <= 100
        // 0 <= k <= 20
        if (i < 0 || i >= m || j < 0 || j >= n || (i / 10 + i % 10 + j / 10 + j % 10) > k || visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        return dfs(i + 1, j, m, n, k, visited) + dfs(i, j + 1, m, n, k, visited) + 1;
    }
};

// @BFS
class Solution_1 {
   public:
    int movingCount(int m, int n, int k) {
        queue<pair<int, int>> bucket;
        bucket.push({0, 0});

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        int dx[2]{0, 1};
        int dy[2]{1, 0};
        int ans = 1;
        while (!bucket.empty()) {
            auto [x, y] = bucket.front();
            bucket.pop();
            for (int i = 0; i < 2; i++) {
                x += dx[i];
                y += dy[i];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || get(x) + get(y) > k) {
                    continue;
                }
                ans++;
                visited[x][y] = true;
                bucket.push({x, y});
            }
        }
        return ans;
    }

   private:
    // 计算 x 的数位之和
    int get(int x) {
        int res = 0;
        for (; x != 0; x /= 10) {
            res += x % 10;
        }
        return res;
    }
};

/*
 * 定义 vis[i][j] 为 (i, j) 坐标是否可达，如果可达返回 1，否则返回 0。
 */
class Solution_2 {
   public:
    int movingCount(int m, int n, int k) {
        if (!k)
            return 1;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int ans = 1;
        vis[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 && j == 0) || get(i) + get(j) > k)
                    continue;
                // 边界判断
                if (i - 1 >= 0)
                    vis[i][j] |= vis[i - 1][j];
                if (j - 1 >= 0)
                    vis[i][j] |= vis[i][j - 1];
                ans += vis[i][j];
            }
        }
        return ans;
    }

   private:
    // 计算 x 的数位之和
    int get(int x) {
        int res = 0;
        for (; x; x /= 10) {
            res += x % 10;
        }
        return res;
    }
};
