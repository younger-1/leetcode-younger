#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution:
    # 200/200 cases passed (68 ms)
    # Your runtime beats 89.52 % of python3 submissions
    # Your memory usage beats 14.93 % of python3 submissions (15.8 MB)
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


# @lc code=end
