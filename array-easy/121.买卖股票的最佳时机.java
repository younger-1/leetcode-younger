/*
 * @lc app=leetcode.cn id=121 lang=java
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
    // 210/210 cases passed (1 ms)
    // Your runtime beats 98.21 % of java submissions
    // Your memory usage beats 5.02 % of java submissions (51.3 MB)
    public int maxProfit(int[] prices) {
        int min_price = Integer.MAX_VALUE;
        int max_profit = 0;

        for (int p : prices) {
            min_price = Math.min(min_price, p);
            max_profit = Math.max(max_profit, p - min_price);
        }

        return max_profit;
    }
}
// @lc code=end

