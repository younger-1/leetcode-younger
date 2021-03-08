#
# @lc app=leetcode.cn id=98 lang=python3
#
# [98] 验证二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB# 52ms 15.8MB


# 52ms 15.8MB
# @BFS
class Solution:
    def isValidBST(self, root):
        def BFS(root, left, right):
            if root is None:
                return True
            if left < root.val < right:
                return BFS(root.left, left, root.val) and BFS(root.right, root.val, right)
            else:
                return False

        return BFS(root, -float("inf"), float("inf"))


# @lc code=end
