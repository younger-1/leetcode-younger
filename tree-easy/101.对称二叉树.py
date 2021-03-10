#
# @lc app=leetcode.cn id=101 lang=python3
#
# [101] 对称二叉树
#

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start

# 194/194 cases passed (40 ms)
# Your runtime beats 81.55 % of python3 submissions
# Your memory usage beats 38.53 % of python3 submissions (15 MB)
class Solution:
    # 迭代
    def isSymmetric(self, root: TreeNode) -> bool:
        # 初始化时我们把根节点入队两次
        queue = [root, root]
        # 每次提取两个结点并比较它们的值
        while queue:
            x = queue.pop(0)
            y = queue.pop(0)
            if x is None and y is None:
                continue
            if x is None or y is None or x.val != y.val:
                return False
            queue.append(x.left)
            queue.append(y.right)
            queue.append(x.right)
            queue.append(y.left)

        return True


# @lc code=end

# 194/194 cases passed (40 ms)
# Your runtime beats 81.48 % of python3 submissions
# Your memory usage beats 5.09 % of python3 submissions (15.2 MB)
class Solution_0:
    # 递归
    def isSymmetric(self, root: TreeNode) -> bool:
        def symTree(left: TreeNode, right: TreeNode) -> bool:
            if left is None and right is None:
                return True
            if left is None or right is None or left.val != right.val:
                return False
            return symTree(left.left, right.right) and symTree(left.right, right.left)

        return symTree(root.left, root.right)
