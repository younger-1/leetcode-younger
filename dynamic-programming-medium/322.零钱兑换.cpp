/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include <cmath>
#include <functional>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start

// 185/185 cases passed (84 ms)
// Your runtime beats 72.64 % of cpp submissions
// Your memory usage beats 51.72 % of cpp submissions (13.7 MB)
// DP 数组的迭代解法
class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = x 表示，当目标金额为 i 时，至少需要x枚硬币
        // note: amount + 1
        vector<int> dp(amount + 1, amount + 1);
        // base case
        dp[0] = 0;
        for (int i = 1; i < amount + 1; i++) {
            for (int c : coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// @lc code=end

// 185/185 cases passed (728 ms)
// Your runtime beats 5.07 % of cpp submissions
// Your memory usage beats 4.99 % of cpp submissions (62.1 MB)
// 带备忘录的递归
class Solution_1 {
   public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> memo;
        // 调用自己时不能用 auto 推导类型
        function<int(int)> dp = [&](int n) {
            if (n == 0) {
                return 0;
            } else if (n < 0) {
                return -1;
            }

            if (memo.find(n) != memo.end()) {
                return memo[n];
            }

            int res = INT_MAX;
            for (int c : coins) {
                int subproblem = dp(n - c);
                if (subproblem == -1) {
                    continue;
                }
                res = min(res, 1 + subproblem);
            }
            memo[n] = res == INT_MAX ? -1 : res;
            return memo[n];
        };

        return dp(amount);
    }
};
