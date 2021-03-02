#
# @lc app=leetcode.cn id=92 lang=python3
#
# [92] 反转链表 II
#

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


# @lc code=start
class Solution:
    # 44/44 cases passed (56 ms)
    # Your runtime beats 5.76 % of python3 submissions
    # Your memory usage beats 20.37 % of python3 submissions (15.1 MB)
    def reverseN(self, head: ListNode, N: int) -> ListNode:
        if N == 1:
            self.join = head.next
            return head
        last = self.reverseN(head.next, N - 1)
        head.next.next = head
        head.next = self.join
        return last

    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        if left == 1:
            return self.reverseN(head, right)

        head.next = self.reverseBetween(head.next, left - 1, right - 1)
        return head


# @lc code=end


class Solution_1:
    # 执行用时： 56 ms , 在所有 Python3 提交中击败了 5.72% 的用户
    # 内存消耗： 14.9 MB , 在所有 Python3 提交中击败了 67.80% 的用户
    def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
        dummy = ListNode()
        dummy.next = head
        pre = dummy
        # Let pre is (left - 1) node
        for _ in range(left - 1):
            pre = pre.next
        # Let cur is (left) node
        cur = pre.next
        for _ in range(right - left):
            tmp = pre.next
            pre.next = cur.next
            cur.next = cur.next.next
            pre.next.next = tmp
        # Note: not return head:
        # eg.[3, 5], left=1, right=2, return head will cause reversed list to be [3]
        return dummy.next
