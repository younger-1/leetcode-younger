/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 269/269 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 30.74 % of cpp submissions (6.1 MB)
class Solution {
   private:
    int dfs(string& s, vector<int>& mem, int n) {
        if (n < 0) {
            return 1;
        }
        if (mem[n] != -1) {
            return mem[n];
        }
        int res = 0;
        if (n == 0) {
            // For "0"
            if (s[n] != '0') {
                res = 1;
            } else {
                res = 0;
            }
        } else if (s[n] == '0') {
            // For "00"
            if (isValid(s[n - 1], s[n])) {
                res = dfs(s, mem, n - 2);
            } else {
                res = 0;
            }
        } else if (n - 1 >= 0 && isValid(s[n - 1], s[n])) {
            res = dfs(s, mem, n - 1) + dfs(s, mem, n - 2);
        } else {
            res = dfs(s, mem, n - 1);
        }

        mem[n] = res;
        return res;
    }

    bool isValid(char a, char b) {
        if (a == '1') {
            return true;
        } else if (a == '2' && b - '0' <= 6) {
            return true;
        }
        return false;
    }

   public:
    // 1230
    int numDecodings(string s) {
        int n = s.size();
        vector<int> mem(n, -1);
        return dfs(s, mem, n - 1);
    }
};
// @lc code=end
