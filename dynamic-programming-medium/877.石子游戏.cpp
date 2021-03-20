/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    // DP
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = piles[i];
        }

        // 在计算 dp 的第 i 行的值时，只需要使用到 dp 的第 i 行和第 i+1 行的值，
        // 因此可以使用一维数组代替二维数组，对空间进行优化
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
            }
        }
        return dp[n];
    }
};

// @lc code=end

// 执行用时： 24 ms , 在所有 C++ 提交中击败了 35.94% 的用户
// 内存消耗： 16.1 MB , 在所有 C++ 提交中击败了 22.60% 的用户
class Solution_1 {
   public:
    // DP
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            dp[i][i] = piles[i];
        }

        // 斜着遍历: j 向右，i 向下
        for (int k = 1; k < n; k++) {
            for (int i = 0; i < n - k; i++) {
                int j = i + k;
                // dp[i][j] 表示当剩下的石子堆为下标 i 到下标 j 时，当前玩家与另一个玩家的石子数量之差的最大值
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }

        // 水平遍历: i 向上，j 向右
        // for (int i = n - 2; i >= 0; i--) {
        //     for (int j = i + 1; j < n; j++) {
        //         dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
        //     }
        // }

        return dp[0][n - 1] > 0;
    }
};
