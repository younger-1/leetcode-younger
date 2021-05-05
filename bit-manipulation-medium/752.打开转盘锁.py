#
# @lc app=leetcode.cn id=752 lang=python3
#
# [752] 打开转盘锁
#
from collections import deque


# @lc code=start
class Solution:
    def openLock(self, deadends, target: str) -> int:
        def neighbors(node):
            for i in range(4):
                x = int(node[i])
                for d in (-1, 1):
                    y = (x + d) % 10
                    yield node[:i] + str(y) + node[i + 1:]

        dead = set(deadends)
        queue = deque([('0000', 0)])
        seen = {'0000'}
        while queue:
            node, depth = queue.popleft()
            if node == target:
                return depth
            if node in dead:
                continue
            for nei in neighbors(node):
                if nei not in seen:
                    seen.add(nei)
                    queue.append((nei, depth + 1))
        return -1


# @lc code=end
