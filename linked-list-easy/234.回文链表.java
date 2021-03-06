/*
 * @lc app=leetcode.cn id=234 lang=java
 *
 * [234] 回文链表
 */

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

// @lc code=start

// 84/84 cases passed (4 ms)
// Your runtime beats 29.03 % of java submissions
// Your memory usage beats 5.01 % of java submissions (48.4 MB)
class Solution {
    /* 「双指针技巧」优化空间复杂度 */
    public boolean isPalindrome(ListNode head) {
        ListNode slow, fast;
        slow = fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        if (fast != null) {
            slow = slow.next;
        }
        ListNode left = head;
        ListNode right = reverse(slow);
        
        while (right != null) {
            if (left.val != right.val) {
                return false;
            }
            left = left.next;
            right = right.next;
        }
        return true;
    }

    ListNode reverse(ListNode head) {
        ListNode pre = null, cur = head;
        while (cur != null) {
            ListNode tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
}
// @lc code=end

// 84/84 cases passed (19 ms)
// Your runtime beats 6.18 % of java submissions
// Your memory usage beats 5.01 % of java submissions (55.3 MB)
class Solution_1 {
    // 左侧指针
    ListNode left;

    public boolean isPalindrome(ListNode head) {
        this.left = head;
        return traverse(head);
    }

    boolean traverse(ListNode right) {
        if (right == null) {
            return true;
        }
        boolean res = traverse(right.next);
        // 后序遍历代码
        res = res && (right.val == left.val);
        left = left.next;
        return res;
    }
}

