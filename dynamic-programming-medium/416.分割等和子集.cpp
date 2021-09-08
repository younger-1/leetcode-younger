/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <vector>

using namespace std;

// @lc code=start

// 116/116 cases passed (352 ms)
// Your runtime beats 26.46 % of cpp submissions
// Your memory usage beats 36.2 % of cpp submissions (11.6 MB)
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int n = nums.size();
        sum /= 2;
        // dp[i][j] = x表示，通过选取前 i 个物品，当前背包的容量为 j 时，若 x 为 true，则说明可以恰好将背包装满
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

        // Base case: 背包的容量为 0 时, 不装也是 true
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sum; j++) {
                // 背包容量不足，不能装入第 i 个物品
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // 不装入或装入背包
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }

        return dp[n][sum];
    }
};
// @lc code=end

// 状态压缩: 用一行表示原dp的每一行, (原dp的第i行由第i-1行推断)
// 通用压缩：两行数组，无需关心内循环遍历顺序：dp[i & 1][j] = fun(dp[(i-1)&1][j], ...)
class Solution_1 {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0)
            return false;
        sum = sum / 2;
        vector<bool> dp(sum + 1, false);
        // base case
        dp[0] = true;

        for (int i = 0; i < n; i++)
            for (int j = sum; j >= 0; j--)
                if (j - nums[i] >= 0)
                    dp[j] = dp[j] || dp[j - nums[i]];

        return dp[sum];
    }
};
