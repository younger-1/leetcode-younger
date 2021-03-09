#
# @lc app=leetcode.cn id=104 lang=python3
#
# [104] 二叉树的最大深度
#

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# @lc code=start


# 39/39 cases passed (44 ms)
# Your runtime beats 90.22 % of python3 submissions
# Your memory usage beats 72.09 % of python3 submissions (15.9 MB)
class Solution:
    """
    我们也可以用「广度优先搜索」的方法来解决这道题目，但我们需要对其进行一些修改，此时我们广度优先搜索的队列里存放的是「当前层的所有节点」。
    每次拓展下一层的时候，不同于广度优先搜索的每次只从队列里拿出一个节点，我们需要将队列里的所有节点都拿出来进行拓展，这样能保证每次拓展完的时候队列里存放的是当前层的所有节点，
    即我们是一层一层地进行拓展，最后我们用一个变量 ans 来维护拓展的次数，该二叉树的最大深度即为 ans。
    """

    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        queue = [root]
        ans = 0
        while queue:
            ans += 1
            layer = queue.copy()
            queue.clear()
            for node in layer:
                if node.left is not None:
                    queue.append(node.left)
                if node.right is not None:
                    queue.append(node.right)
        return ans


# @lc code=end

# 39/39 cases passed (40 ms)
# Your runtime beats 97.07 % of python3 submissions
# Your memory usage beats 18.59 % of python3 submissions (16.6 MB)
class Solution_0:
    # 深度优先搜索
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))
