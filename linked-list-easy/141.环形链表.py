#
# @lc app=leetcode.cn id=141 lang=python3
#
# [141] 环形链表
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# @lc code=start

# 19/19 cases passed (56 ms)
# Your runtime beats 81.93 % of python3 submissions
# Your memory usage beats 40.65 % of python3 submissions (18 MB)
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        fast, slow = head, head
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
            if fast is slow:
                return True
        return False


# @lc code=end
