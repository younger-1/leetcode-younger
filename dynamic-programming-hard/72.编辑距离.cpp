/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 1146/1146 cases passed (8 ms)
// Your runtime beats 90.85 % of cpp submissions
// Your memory usage beats 41.71 % of cpp submissions (8.8 MB)
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        // word1 前 i 个与 word2 前 j 个的最小编辑距离
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // base case
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 插入，删除，替换
                    dp[i][j] = min_3(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[m][n];
    }

    int min_3(int a, int b, int c) { return min(a, min(b, c)); }
};
// @lc code=end
