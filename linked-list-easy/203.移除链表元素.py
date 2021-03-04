#
# @lc app=leetcode.cn id=203 lang=python3
#
# [203] 移除链表元素
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @lc code=start

# 执行用时： 72 ms , 在所有 Python3 提交中击败了 60.10% 的用户
# 内存消耗： 17.8 MB , 在所有 Python3 提交中击败了 69.90% 的用户
class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        # For situation like: [2], 2
        dummy = ListNode(0, head)
        pre, cur = dummy, head
        while cur is not None:
            if cur.val == val:
                pre.next = cur.next
            else:
                pre = cur
            cur = cur.next
        # For situation like: [2], 2
        return dummy.next


# @lc code=end
