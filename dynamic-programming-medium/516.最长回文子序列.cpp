/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        /*
              0 1 2 3 (j)
            0
            1
            2
            3
            (i)
         */
        for (int j = 1; j < n; j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

// 将字符串翻转，然后求两个字符串的最长公共子序列就可以了
// https://leetcode-cn.com/problems/longest-palindromic-subsequence/solution/zui-chang-hui-wen-zi-xu-lie-by-leetcode-hcjqp/1075900
class Solution_1 {
   public:
    int longestPalindromeSubseq(string s) {}
};
