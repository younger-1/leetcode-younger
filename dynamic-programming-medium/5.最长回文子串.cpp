/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1;
        int begin = 0;
        for (int i = 0; i < n - 1; i++) {
            int p1 = getPalindrome(s, i, i);
            int p2 = getPalindrome(s, i, i + 1);
            int p = max(p1, p2);
            if (p > maxLen) {
                maxLen = p;
                begin = i - (p - 1) / 2;
            }
        }
        return s.substr(begin, maxLen);
    }
    int getPalindrome(string& s, int i, int j) {
        int n = s.length();
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
        }
        return j - i - 1;
    }
};
// @lc code=end

class Solution_0 {
   public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1, idx = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = true;
            for (int j = i + 1; j < n; j++) {
                // nice
                if (j == i + 1) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                }

                if (dp[i][j]) {
                    if (maxLen < j - i + 1) {
                        maxLen = j - i + 1;
                        idx = i;
                    }
                }
            }
        }
        return s.substr(idx, maxLen);
    }
};
