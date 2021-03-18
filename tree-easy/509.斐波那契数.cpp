/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

#include <vector>

using namespace std;

// @lc code=start

// 31/31 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 80.66 % of cpp submissions (6 MB)
// DP
class Solution {
   public:
    int fib(int n) {
        // WDNMD, 下面 for 循环的 n 不能小于 2
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        // base case
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    int fib_(int n) {
        if (n == 0)
            return 0;
        if (n == 2 || n == 1)
            return 1;
        int prev = 1, curr = 1;
        for (int i = 3; i <= n; i++) {
            int sum = prev + curr;
            prev = curr;
            curr = sum;
        }
        return curr;
    }
};

// @lc code=end

// Time Limit Exceeded
class Solution_1 {
   public:
    int fib(int n) {
        vector<int> memo(n + 1, 0);
        return helper(memo, n);
    }

    int helper(vector<int> memo, int n) {
        if (n < 2) {
            return n;
        }
        memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
        return memo[n];
    }
};

// 矩阵快速幂
// ?: what the hell
class Solution_2 {
   public:
    int fib(int n) {
        if (n < 2) {
            return n;
        }
        vector<vector<int>> q{{1, 1}, {1, 0}};
        vector<vector<int>> res = matrix_pow(q, n - 1);
        return res[0][0];
    }

    vector<vector<int>> matrix_pow(vector<vector<int>>& a, int n) {
        vector<vector<int>> ret{{1, 0}, {0, 1}};
        while (n > 0) {
            if (n & 1) {
                ret = matrix_multiply(ret, a);
            }
            n >>= 1;
            a = matrix_multiply(a, a);
        }
        return ret;
    }

    vector<vector<int>> matrix_multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> c{{0, 0}, {0, 0}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
            }
        }
        return c;
    }

    // 非递归快速幂
    // https://zhuanlan.zhihu.com/p/95902286
    int qpow(int a, int n) {
        int res = 1;
        while (n > 0) {
            if (n & 1) {
                res *= a;
            }
            a *= a;
            n >>= 1;
        }
        return res;
    }
};

#include <cmath>
class Solution_3 {
   public:
    int fib(int n) {
        double sqrt5 = sqrt(5);
        double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
        return round(fibN / sqrt5);
    }
};