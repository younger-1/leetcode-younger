/*
 * @lc app=leetcode.cn id=122 lang=rust
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
impl Solution {
    // 200/200 cases passed (0 ms)
    // Your runtime beats 100 % of rust submissions
    // Your memory usage beats 87.88 % of rust submissions (2.1 MB)
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        prices.windows(2).map(|x| 0.max(x[1] - x[0])).sum()
    }
}
// @lc code=end
