#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    # 210/210 cases passed (108 ms)
    # Your runtime beats 12.65 % of python3 submissions
    # Your memory usage beats 5.01 % of python3 submissions (23.5 MB)
    def maxProfit(self, prices: list[int]) -> int:
        if not prices:
            return 0

        min_price = max(prices)
        max_profit = 0

        for p in prices:
            if p < min_price:
                min_price = p
            elif p - min_price > max_profit:
                max_profit = p - min_price

        return max_profit


# @lc code=end
