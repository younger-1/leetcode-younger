#
# @lc app=leetcode.cn id=338 lang=python3
#
# [338] 比特位计数
#

# @lc code=start
class Solution:
    # 执行用时： 84 ms , 在所有 Python3 提交中击败了 84.20% 的用户
    # 内存消耗： 21.3 MB , 在所有 Python3 提交中击败了 43.29% 的用户
    def countBits(self, num: int) -> list[int]:
        bits = [0]
        while len(bits) < num + 1:
            bits.extend([bit + 1 for bit in bits])
        return bits[: num + 1]


# @lc code=end

# 动态规划——最高有效位
class Solution_1:
    def countBits(self, num: int) -> list[int]:
        bits = [0]
        # highBit 表示当前最大 2 的整数次幂
        highBit = 0
        for i in range(1, num + 1):
            if i & (i - 1) == 0:
                highBit = i
            bits.append(bits[i - highBit] + 1)
        return bits


# 动态规划——最低有效位
class Solution_2:
    def countBits(self, num: int) -> list[int]:
        bits = [0]
        for i in range(1, num + 1):
            # 分奇偶
            bits.append(bits[i >> 1] + (i & 1))
        return bits
