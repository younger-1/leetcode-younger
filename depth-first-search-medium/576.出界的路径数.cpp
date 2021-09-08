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
// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/out-of-boundary-paths/solution/chu-jie-de-lu-jing-shu-by-leetcode-solut-l9dw/
class Solution_2 {
   public:
    static constexpr int MOD = 1'000'000'007;

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int outCounts = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; i++) {
            vector<vector<int>> dpNew(m, vector<int>(n));
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    int count = dp[j][k];
                    if (count > 0) {
                        for (auto& direction : directions) {
                            int j1 = j + direction[0], k1 = k + direction[1];
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
