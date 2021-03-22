#
# @lc app=leetcode.cn id=887 lang=python3
#
# [887] 鸡蛋掉落
#

# @lc code=start
class Solution:
    # 动态规划 + 二分查找
    def superEggDrop(self, k: int, n: int) -> int:
        pass


# @lc code=end

# 121/121 cases passed (2896 ms)
# Your runtime beats 13.62 % of python3 submissions
# Your memory usage beats 5.47 % of python3 submissions (44.3 MB)
class Solution_2:
    # 动态规划 + 二分查找
    def superEggDrop(self, k: int, n: int) -> int:
        memo = dict()

        def dp(eggs: int, floors: int) -> int:
            if eggs == 1:
                return floors
            if floors == 0:
                return 0

            if (eggs, floors) in memo:
                return memo[eggs, floors]

            res = floors
            left, right = 1, floors
            while left <= right:
                mid = (left + right) // 2
                broken = dp(eggs - 1, mid - 1)
                not_broken = dp(eggs, floors - mid)
                if broken > not_broken:
                    right = mid - 1
                    res = min(res, broken + 1)
                else:
                    left = mid + 1
                    res = min(res, not_broken + 1)
            memo[eggs, floors] = res
            return res

        return dp(k, n)


# Time Limit Exceeded
class Solution_1:
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
