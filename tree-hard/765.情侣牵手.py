#
# @lc app=leetcode.cn id=765 lang=python3
#
# [765] 情侣牵手
#

# @lc code=start
class Solution:
    # 56/56 cases passed (36 ms)
    # Your runtime beats 91.81 % of python3 submissions
    # Your memory usage beats 87.06 % of python3 submissions (14.7 MB)
    def minSwapsCouples(self, row: list[int]) -> int:
        uf = UnionFind(len(row) // 2)
        for i in range(0, len(row), 2):
            uf.union(row[i] // 2, row[i + 1] // 2)
        return uf.count


class UnionFind:
    def __init__(self, n: int):
        self.count = 0
        self.parent = [i for i in range(n)]

    def find(self, x) -> int:
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int) -> None:
        px = self.find(x)
        py = self.find(y)
        if px != py:
            self.parent[px] = py
            self.count += 1


# @lc code=end


class Solution_1:
    # 执行用时： 48 ms , 在所有 Python3 提交中击败了 22.26% 的用户
    # 内存消耗： 14.6 MB , 在所有 Python3 提交中击败了 91.51% 的用户
    def minSwapsCouples(self, row: list[int]) -> int:
        def find_another(n):
            return n + 1 if n % 2 == 0 else n - 1

        c = 0
        for i in range(0, len(row), 2):
            p1 = row[i]
            p2 = find_another(p1)
            if row[i + 1] != p2:
                j = row.index(p2)
                row[i + 1], row[j] = row[j], row[i + 1]
                c += 1
        return c


class Solution_2:
    # 56/56 cases passed (36 ms)
    # Your runtime beats 91.81 % of python3 submissions
    # Your memory usage beats 86.15 % of python3 submissions (14.7 MB)
    #
    # i = 1
    #   1 3, 4 6, 2 5, 0 7
    # exchange 3 and 5. 2 3 is done
    #   1 5, 4 6, 2 3, 0 7
    # exchange 5 and 6. 4 5 is done
    #   1 6, 4 5, 2 3, 0 7
    # exchange 6 and 0. All is done
    #   1 0, 4 5, 2 3, 6 7
    def minSwapsCouples(self, row: list[int]) -> int:
        N = len(row)
        pos = {val: i for i, val in enumerate(row)}
        ans = 0
        for i in range(1, N, 2):
            # Note: while
            while row[i - 1] != row[i] ^ 1:
                # Let row[i] to be exchanged to beside his/her love
                # exchange_index is the seat beside row[i]'s love
                exchange_index = pos[row[i] ^ 1] ^ 1
                row[i], row[exchange_index] = row[exchange_index], row[i]
                ans += 1
        return ans


class Solution_3:
    # 56/56 cases passed (44 ms)
    # Your runtime beats 50.49 % of python3 submissions
    # Your memory usage beats 96.34 % of python3 submissions (14.6 MB)
    def minSwapsCouples(self, row: list[int]) -> int:
        # 使用哈希表维护字符索引，每次遍历一对交换
        d = {num: idx for idx, num in enumerate(row)}
        cnt = 0
        for i in range(0, len(row), 2):
            lover = row[i] ^ 1
            if row[i + 1] != lover:
                row[i + 1], row[d[lover]] = row[d[lover]], row[i + 1]
                x, y = row[i + 1], row[d[lover]]
                # Update dict
                d[x], d[y] = d[y], d[x]
                cnt += 1
        return cnt
