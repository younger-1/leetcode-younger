#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start

# 200/200 cases passed (48 ms)
# Your runtime beats 67.63 % of python3 submissions
# Your memory usage beats 99.25 % of python3 submissions (15.3 MB)
class Solution:
    # 可读性更好
    def maxProfit(self, prices: list[int]) -> int:
        profit = 0
        for i in range(1, len(prices)):
            profit += max(0, prices[i] - prices[i - 1])
        return profit


# @lc code=end

# 200/200 cases passed (68 ms)
# Your runtime beats 89.52 % of python3 submissions
# Your memory usage beats 14.93 % of python3 submissions (15.8 MB)
class Solution_0:
    def maxProfit(self, prices: list[int]) -> int:
        left, right, profit = 0, 0, 0
        for i in range(len(prices) - 1):
            if prices[i] > prices[i + 1]:
                profit += prices[right] - prices[left]
                left, right = i + 1, i + 1
            else:
                right = i + 1
        profit += prices[right] - prices[left]
        return profit
