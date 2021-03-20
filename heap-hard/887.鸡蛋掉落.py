#
# @lc app=leetcode.cn id=887 lang=python3
#
# [887] 鸡蛋掉落
#

# @lc code=start
class Solution:
    # 动态规划 + 二分查找
    def superEggDrop(self, k: int, n: int) -> int:
        memo = dict()

        def dp(eggs: int, floors: int) -> int:
            pass

        return dp(k, n)


# @lc code=end

# Time Limit Exceeded
class Solution_0:
    # 动态规划
    def superEggDrop(self, k: int, n: int) -> int:
        memo = dict()

        def dp(eggs: int, floors: int) -> int:
            # base case:
            if eggs == 1:
                return floors
            if floors == 0:
                return 0

            # 备忘录
            if (eggs, floors) in memo:
                return memo[(eggs, floors)]

            res = float("inf")
            for i in range(1, floors + 1):
                res = min(res, 1 + max(dp(eggs - 1, i - 1), dp(eggs, floors - i)))

            memo[(eggs, floors)] = res
            return res

        return dp(k, n)
