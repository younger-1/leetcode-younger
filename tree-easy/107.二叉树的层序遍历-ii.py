#
# @lc app=leetcode.cn id=107 lang=python3
#
# [107] 二叉树的层序遍历 II
#

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start

# 34/34 cases passed (40 ms)
# Your runtime beats 75.19 % of python3 submissions
# Your memory usage beats 7.82 % of python3 submissions (15.6 MB)
class Solution_1:
    # DFS
    def levelOrderBottom(self, root: TreeNode) -> list[list[int]]:
        def dfs(level: int, node: TreeNode) -> None:
            if node is None:
                return
            if len(res) < level + 1:
                res.insert(0, [])
            res[len(res) - level - 1].append(node.val)
            dfs(level + 1, node.left)
            dfs(level + 1, node.right)

        res = []
        dfs(0, root)
        return res


# @lc code=end

# 34/34 cases passed (40 ms)
# Your runtime beats 75.19 % of python3 submissions
# Your memory usage beats 14.91 % of python3 submissions (15.3 MB))
class Solution:
    # BFS
    def levelOrderBottom(self, root: TreeNode) -> list[list[int]]:
        res = []
        from collections import deque

        queue = deque([root])
        while queue:
            layer = []
            n = len(queue)
            for _ in range(n):
                node = queue.popleft()
                if node is None:
                    continue
                queue.append(node.left)
                queue.append(node.right)
                layer.append(node.val)
            if layer:
                res.append(layer)
        return res[::-1]
