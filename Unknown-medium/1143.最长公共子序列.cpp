/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include <map>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

// 44/44 cases passed (1352 ms)
// Your runtime beats 5.57 % of cpp submissions
// Your memory usage beats 5.2 % of cpp submissions (99.8 MB)
class Solution_1 {
   private:
    string str1;
    string str2;
    map<pair<int, int>, int> memo;
    int dfs(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }
        if (memo.find({a, b}) != memo.end()) {
            return memo[{a, b}];
        }
        int res;
        if (str1[a - 1] == str2[b - 1]) {
            res = 1 + dfs(a - 1, b - 1);
        } else {
            res = max(dfs(a, b - 1), dfs(a - 1, b));
        }
        memo[{a, b}] = res;
        return res;
    }

   public:
    int longestCommonSubsequence(string text1, string text2) {
        str1 = text1;
        str2 = text2;
        int n = str1.length();
        int m = str2.length();

        return dfs(n, m);
    }
};

// 44/44 cases passed (32 ms)
// Your runtime beats 34.72 % of cpp submissions
// Your memory usage beats 40.62 % of cpp submissions (12.7 MB)
class Solution_0 {
   private:
    string str1;
    string str2;
    int **memo;
    int dfs(int a, int b) {
        if (a == 0 || b == 0) {
            return 0;
        }
        if (memo[a - 1][b - 1] != -1) {
            return memo[a - 1][b - 1];
        }
        int res;
        if (str1[a - 1] == str2[b - 1]) {
            res = 1 + dfs(a - 1, b - 1);
        } else {
            res = max(dfs(a, b - 1), dfs(a - 1, b));
        }
        memo[a - 1][b - 1] = res;
        return res;
    }

   public:
    int longestCommonSubsequence(string text1, string text2) {
        str1 = text1;
        str2 = text2;
        int n = str1.length();
        int m = str2.length();

        memo = new int *[n];
        for (int i = 0; i < n; i++) {
            memo[i] = new int[m];
            for (int j = 0; j < m; j++) {
                memo[i][j] = -1;
            }
        }
        return dfs(n, m);
    }
};
