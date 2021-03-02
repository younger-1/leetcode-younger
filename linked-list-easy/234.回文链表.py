#
# @lc app=leetcode.cn id=234 lang=python3
#
# [234] 回文链表
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @lc code=start
class Solution:
    # 26/26 cases passed (96 ms)
    # Your runtime beats 16.79 % of python3 submissions
    # Your memory usage beats 8.26 % of python3 submissions (65.6 MB)
    def isPalindrome(self, head: ListNode) -> bool:
        self.left = head
        return self.traverse(head)

    def traverse(self, head: ListNode) -> bool:
        if head is None:
            return True
        res = self.traverse(head.next)
        res = res and head.val == self.left.val
        self.left = self.left.next
        return res


# @lc code=end
