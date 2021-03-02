#
# @lc app=leetcode.cn id=25 lang=python3
#
# [25] K 个一组翻转链表
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @lc code=start
class Solution:
    # 62/62 cases passed (56 ms)
    # Your runtime beats 59.17 % of python3 submissions
    # Your memory usage beats 5.17 % of python3 submissions (16.2 MB)
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        head_k = head
        for _ in range(k):
            if head_k is None:
                return head
            head_k = head_k.next
        # Reverse [head, head_k)
        newHead = self.reverse(head, head_k)
        # Concatenate
        head.next = self.reverseKGroup(head_k, k)
        return newHead

    def reverse(self, head, tail):
        if head.next == tail:
            return head
        last = self.reverse(head.next, tail)
        head.next.next = head
        head.next = tail
        return last

    def reverse_iter(self, head, tail):
        pre, cur, nxt = None, head, head
        while cur != tail:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre


# @lc code=end
