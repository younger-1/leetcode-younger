/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
 */

#include <iostream>
#include <vector>

using namespace std;

#include <array>
#include <vector>

using namespace std;

// @lc code=start
// @lc code=end

// @DP
// 定义 dp[i][j][k] 表示球移动 i 次之后位于坐标 (j,k) 的路径数量。
// 链接：https://leetcode-cn.com/problems/out-of-boundary-paths/solution/chu-jie-de-lu-jing-shu-by-leetcode-solut-l9dw/
class Solution_3 {
   public:
    static constexpr int MOD = 1'000'000'007;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int outCounts = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        for (int k = 0; k < maxMove; k++) {
            vector<vector<int>> dpNew(m, vector<int>(n));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int count = dp[i][j];
                    if (count > 0) {
                        for (auto& direction : directions) {
                            int j1 = i + direction[0], k1 = j + direction[1];
                            if (j1 >= 0 && j1 < m && k1 >= 0 && k1 < n) {
                                dpNew[j1][k1] = (dpNew[j1][k1] + count) % MOD;
                            } else {
                                outCounts = (outCounts + count) % MOD;
                            }
                        }
                    }
                }
            }
            dp = dpNew;
        }
        return outCounts;
    }
};

// 空间优化: 三维数组压缩为两个二维数组
class Solution_21 {
   public:
    static constexpr int MOD = 1'000'000'007;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) { return 0; }
};

// @DP
// https://leetcode-cn.com/problems/out-of-boundary-paths/comments/5603
// 三维数组存储路径数
// dp[i][j][k]表示从(i, j)开始在k步内移除边界的路径数.
// dp[i][j][k] = dp[i-1][j][k-1] + dp[i+1][j][k-1] + dp[i][j-1][k-1] + dp[i][j+1][k-1];
// TODO: ?
/*
1
3
3
0
1
输出
11
预期结果
12
 */
class Solution_2 {
   public:
    static constexpr int MOD = 1'000'000'007;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        if (maxMove == 0) {
            return 0;
        }
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int outCounts = 0;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1)));
        for (int k = 1; k <= maxMove; k++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    for (auto& direction : directions) {
                        int ni = i + direction[0], nj = j + direction[1];
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) {
                            dp[i][j][k] += 1;
                        } else {
                            dp[i][j][k] = (dp[i][j][k] + dp[ni][nj][k - 1]) % MOD;
                        }
                    }
                }
            }
        }
        return dp[startRow][startRow][maxMove];
    }
};

// @DFS
// 记忆化搜索
// https://leetcode-cn.com/problems/out-of-boundary-paths/solution/yi-ti-wu-jie-dfs-jian-zhi-ji-yi-hua-sou-k4dtg/
class Solution_1 {
   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r = m, c = n;
        memo = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove + 1, 0)));
        return dfs(maxMove, startRow, startColumn);
    }

   private:
    int r, c;
    int dire[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> memo;
    int dfs(int moveCount, int i, int j) {
        // 越界了就找到了一条路径
        if (i < 0 || j < 0 || i >= r || j >= c) {
            return 1;
        }
        // 没有移动次数了，返回0
        if (moveCount == 0) {
            return 0;
        }

        // 剪枝：如果小球不管怎么移动都无法越出网格，那就剪掉这个枝
        if (moveCount <= i && moveCount <= j && i + moveCount < r && j + moveCount < c) {
            return 0;
        }

        // 缓存中存在
        if (memo[i][j][moveCount]) {
            return memo[i][j][moveCount];
        }

        // 从这个点出发的符合条件的路径数量
        int sum = 0;
        for (auto d : dire) {
            sum += dfs(moveCount - 1, i + d[0], j + d[1]);
            sum %= MOD;
        }

        memo[i][j][moveCount] = sum;
        return sum;
    }
};

// Time out
class Solution_0 {
   public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        r = m, c = n;
        dfs(maxMove, startRow, startColumn);
        return ans;
    }

   private:
    int ans, r, c;
    // https://stackoverflow.com/questions/27669200/how-should-i-brace-initialize-an-stdarray-of-stdpairs
    std::array<pair<int, int>, 4> dire{{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
    void dfs(int move, int row, int col) {
        if (row < 0 || col < 0 || row >= r || col >= c) {
            ans++;
        }
        if (0 == move) {
            return;
        }
        for (auto [i, j] : dire) {
            move--;
            dfs(move, row + i, col + j);
            move++;
        }
    }
};
