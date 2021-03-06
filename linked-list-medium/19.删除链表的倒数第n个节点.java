/*
 * @lc app=leetcode.cn id=19 lang=java
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */


// 208/208 cases passed (0 ms)
// Your runtime beats 100 % of java submissions
// Your memory usage beats 70.75 % of java submissions (36.3 MB)
class Solution {
    /* Double pointer */
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode first = head;
        ListNode second = dummy;
        for (int i = 0; i < n; i++) {
            first = first.next;
        }
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        second.next = second.next.next;
        return dummy.next;
    }
}
// @lc code=end


// 执行用时： 1 ms , 在所有 Java 提交中击败了 18.25% 的用户 
// 内存消耗： 36.2 MB , 在所有 Java 提交中击败了 93.02% 的用户
class Solution_0 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        List<ListNode> nodes = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            nodes.add(cur);
            cur = cur.next;
        }
        if (nodes.size() - n - 1 == -1) {
            return head.next;
        }
        ListNode beforeRemove = nodes.get(nodes.size() - n - 1);
        beforeRemove.next = beforeRemove.next.next;
        return head;
    }
}